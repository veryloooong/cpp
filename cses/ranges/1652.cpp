#include <algorithm>
#include <chrono>
#include <cstdint>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

constexpr i64 MOD = 1e9 + 7; // NOLINT

const char *inf = "input.txt";
const char *outf = "output.txt";

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << '(' << p.first << ',' << p.second << ')';
  return os;
}

template <typename T> ostream &operator<<(ostream &os, const vector<T> &arr) {
  os << '[';
  for (int i = 0, n = arr.size(); i < n; i++) {
    os << arr[i] << (i < n - 1 ? ", " : "");
  }
  os << ']';

  return os;
}

struct yn_tf : numpunct<char> {
  string do_truename() const { return "YES"; }
  string do_falsename() const { return "NO"; }
};

class SegmentTree {
private:
  vector<vector<i64>> tree;
  int sz;

  void build_y(const vector<vector<int>> &arr, int vx, int lx, int rx, int vy,
               int ly, int ry) {
    if (ly == ry) {
      if (lx == rx)
        tree[vx][vy] = arr[lx][ly];
      else
        tree[vx][vy] = tree[2 * vx][vy] + tree[2 * vx + 1][vy];
    } else {
      int my = (ly + ry) / 2;
      build_y(arr, vx, lx, rx, 2 * vy, ly, my);
      build_y(arr, vx, lx, rx, 2 * vy + 1, my + 1, ry);
      tree[vx][vy] = tree[vx][2 * vy] + tree[vx][2 * vy + 1];
    }
  }

  void build_x(const vector<vector<int>> &arr, int vx, int lx, int rx) {
    if (lx != rx) {
      int mx = (lx + rx) / 2;
      build_x(arr, 2 * vx, lx, mx);
      build_x(arr, 2 * vx + 1, mx + 1, rx);
    }
    build_y(arr, vx, lx, rx, 1, 0, sz - 1);
  }

  void build(const vector<vector<int>> &arr) { build_x(arr, 1, 0, sz - 1); }

  i64 query_y(int vx, int vy, int lby, int rby, int ly, int ry) {
    if (ly > ry)
      return 0;
    if (ly == lby && ry == rby)
      return tree[vx][vy];
    int my = (lby + rby) / 2;
    return query_y(vx, 2 * vy, lby, my, ly, min(ry, my)) +
           query_y(vx, 2 * vy + 1, my + 1, rby, max(ly, my + 1), ry);
  }

  i64 query_x(int vx, int lbx, int rbx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
      return 0;
    if (lx == lbx && rx == rbx)
      return query_y(vx, 1, 0, sz - 1, ly, ry);
    int mx = (lbx + rbx) / 2;
    return query_x(2 * vx, lbx, mx, lx, min(rx, mx), ly, ry) +
           query_x(2 * vx + 1, mx + 1, rbx, max(lx, mx + 1), rx, ly, ry);
  }

public:
  SegmentTree(const vector<vector<int>> &arr)
      : tree(4 * arr.size(), vector<i64>(4 * arr.size())), sz(arr.size()) {
    build(arr);
  }

  i64 query(int lx, int rx, int ly, int ry) {
    return query_x(1, 0, sz - 1, lx, rx, ly, ry);
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> grid(n, vector<int>(n));
  for (int x = 0; x < n; x++) {
    string s;
    cin >> s;
    for (int y = 0; y < n; y++) {
      grid[x][y] = (s[y] == '*' ? 1 : 0);
    }
  }

  SegmentTree st(grid);
  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << st.query(--x1, --x2, --y1, --y2) << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifndef ONLINE_JUDGE
  ifstream in(inf);
  ofstream out(outf);

  if (in.good()) {
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
  }
#endif

  cout.imbue(locale(cout.getloc(), new yn_tf));
  cout << boolalpha;

  solve();

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */
