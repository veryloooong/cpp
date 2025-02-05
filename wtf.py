import flask
import os

app = flask.Flask(__name__)


flag = open("/flag").read().strip() if os.geteuid() == 0 else "pwn.college{fake_flag}"

import sqlite3
import tempfile


class TemporaryDB:
    def __init__(self):
        self.db_file = tempfile.NamedTemporaryFile("x", suffix=".db")

    def execute(self, sql, parameters=()):
        connection = sqlite3.connect(self.db_file.name)
        connection.row_factory = sqlite3.Row
        cursor = connection.cursor()
        result = cursor.execute(sql, parameters)
        connection.commit()
        return result


db = TemporaryDB()

# https://www.sqlite.org/lang_createtable.html
db.execute("""CREATE TABLE posts AS SELECT ? AS content, "admin" AS author, FALSE AS published""", [flag])
db.execute("""CREATE TABLE users AS SELECT "admin" AS username, ? as password""", [flag[-20:]])
# https://www.sqlite.org/lang_insert.html
db.execute("""INSERT INTO users SELECT "guest" as username, "password" as password""")
db.execute("""INSERT INTO users SELECT "hacker" as username, "1337" as password""")


@app.route("/login", methods=["POST"])
def challenge_login():
    username = flask.request.form.get("username")
    password = flask.request.form.get("password")
    if not username:
        flask.abort(400, "Missing `username` form parameter")
    if not password:
        flask.abort(400, "Missing `password` form parameter")

    # https://www.sqlite.org/lang_select.html
    user = db.execute("SELECT * FROM users WHERE username = ? AND password = ?", (username, password)).fetchone()
    if not user:
        flask.abort(403, "Invalid username or password")

    response = flask.redirect("/")
    response.set_cookie("auth", username + "|" + password)
    return response


@app.route("/draft", methods=["POST"])
def challenge_draft():
    username, password = flask.request.cookies.get("auth", "|").split("|")
    user = db.execute("SELECT * FROM users WHERE username = ? AND password = ?", (username, password)).fetchone()
    if not user:
        flask.abort(403, "Invalid username or password")

    if username == "admin":
        flask.abort(400, "pwnpost no longer supports admin posting due to rampant flag disclosure")
    content = flask.request.form.get("content", "")
    # https://www.sqlite.org/lang_insert.html
    db.execute(
        "INSERT INTO posts (content, author, published) VALUES (?, ?, ?)",
        (content, username, bool(flask.request.form.get("publish"))),
    )
    return flask.redirect("/")


@app.route("/publish", methods=["POST"])
def challenge_publish():
    username, password = flask.request.cookies.get("auth", "|").split("|")
    user = db.execute("SELECT * FROM users WHERE username = ? AND password = ?", (username, password)).fetchone()
    if not user:
        flask.abort(403, "Invalid username or password")

    if username == "admin":
        flask.abort(400, "pwnpost no longer supports admin posting due to rampant flag disclosure")
    # https://www.sqlite.org/lang_update.html
    db.execute("UPDATE posts SET published = TRUE WHERE author = ?", [username])
    return flask.redirect("/")


@app.route("/", methods=["GET"])
def challenge_get():
    page = "<html><body>\nWelcome to pwnpost, now with users!<hr>\n"
    username, password = flask.request.cookies.get("auth", "|").split("|")
    user = db.execute("SELECT * FROM users WHERE username = ? AND password = ?", (username, password)).fetchone()
    if user:
        page += """
            <form action=draft method=post>
              Post:<textarea name=content>Write something!</textarea>
              <input type=checkbox name=publish>Publish
              <input type=submit value=Save>
            </form><br>
            <form action=publish method=post><input type=submit value="Publish All Drafts"></form>
            <hr>
        """

        for post in db.execute("SELECT * FROM posts").fetchall():
            page += f"""<h2>Author: {post["author"]}</h2>"""
            if post["published"]:
                page += post["content"] + "<hr>\n"
            elif post["author"] == username:
                page += "<b>YOUR DRAFT POST:</b> " + post["content"] + "<hr>\n"
            else:
                page += f"""(Draft post, showing first 12 characters):<br>{post["content"][:12]}<hr>"""
    else:
        page += """
            <form action=login method=post>
              Username:<input type=text name=username>
              Password:<input type=text name=password>
              <input type=submit name=submit value=Login>
            </form><hr>
        """

    return page + "</body></html>"


app.secret_key = os.urandom(8)
app.config["SERVER_NAME"] = f"challenge.localhost:80"
app.run("challenge.localhost", 80)
