import re

class Reader:
  def __init__(self):
    self.tokens = []

  def token(self):
    while not self.tokens:
      self.tokens = list(reversed(input().split()))
    return self.tokens.pop()


def main():
  reader = Reader()
  hms_str = reader.token()
  if re.match(r"\d{2}:\d{2}:\d{2}", hms_str):
    hms = hms_str.split(":")
    hour, minute, second = int(hms[0]), int(hms[1]), int(hms[2])
    if 0 <= hour <= 23 and 0 <= minute <= 59 and 0 <= second <= 59:
      print(hour * 3600 + minute * 60 + second)
    else:
      print("INCORRECT")
  else:
    print("INCORRECT")


if __name__ == "__main__":
  main()