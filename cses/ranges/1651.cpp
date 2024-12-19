#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
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
  vector<i64> tree;
  int sz;

  void build(const vector<int> &arr, int v, int lb, int rb) {
    if (lb == rb)
      tree[v] = arr[lb];
    else {
      int m = (lb + rb) / 2;
      build(arr, 2 * v, lb, m);
      build(arr, 2 * v + 1, m + 1, rb);
      tree[v] = 0;
    }
  }

  void build(const vector<int> &arr) { build(arr, 1, 0, arr.size() - 1); }

  void update(int v, int lb, int rb, int l, int r, i64 val) {
    if (l > r)
      return;
    if (l == lb && r == rb)
      tree[v] += val;
    else {
      int m = (lb + rb) / 2;
      update(2 * v, lb, m, l, min(r, m), val);
      update(2 * v + 1, m + 1, rb, max(l, m + 1), r, val);
    }
  }

  i64 get(int v, int lb, int rb, int pos) {
    if (lb == rb)
      return tree[v];
    int m = (lb + rb) / 2;
    if (pos <= m)
      return tree[v] + get(2 * v, lb, m, pos);
    else
      return tree[v] + get(2 * v + 1, m + 1, rb, pos);
  }

public:
  SegmentTree(const vector<int> &arr) : tree(4 * arr.size()), sz(arr.size()) {
    build(arr);
  }

  void update(int l, int r, i64 val) { update(1, 0, sz - 1, l, r, val); }

  i64 get(int pos) { return get(1, 0, sz - 1, pos); }
};

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;
  SegmentTree st(arr);

  for (int i = 0; i < q; i++) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int a, b, u;
      cin >> a >> b >> u;
      st.update(--a, --b, u);
    } else if (cmd == 2) {
      int i;
      cin >> i;
      cout << st.get(--i) << '\n';
    }
  }
}

int main() {
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
