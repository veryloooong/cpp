#include <algorithm>
#include <climits>
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
  vector<int> tree;
  int sz;

  void build(const vector<int> &arr, int v, int lb, int rb) {
    if (lb == rb)
      tree[v] = arr[lb];
    else {
      int m = (lb + rb) / 2;
      build(arr, 2 * v, lb, m);
      build(arr, 2 * v + 1, m + 1, rb);
      tree[v] = std::min(tree[2 * v], tree[2 * v + 1]);
    }
  }

  void build(const vector<int> &arr) { build(arr, 1, 0, arr.size() - 1); }

  int min(int v, int lb, int rb, int l, int r) {
    if (l > r)
      return INT_MAX;
    if (l == lb && r == rb)
      return tree[v];
    int m = (lb + rb) / 2;
    return std::min(min(2 * v, lb, m, l, std::min(r, m)),
                    min(2 * v + 1, m + 1, rb, max(l, m + 1), r));
  }

  void update(int v, int lb, int rb, int pos, int val) {
    if (lb == rb)
      tree[v] = val;
    else {
      int m = (lb + rb) / 2;
      if (pos <= m)
        update(2 * v, lb, m, pos, val);
      else
        update(2 * v + 1, m + 1, rb, pos, val);
      tree[v] = std::min(tree[2 * v], tree[2 * v + 1]);
    }
  }

public:
  SegmentTree(const vector<int> &arr) : tree(4 * arr.size()), sz(arr.size()) {
    build(arr);
  }

  int min(int l, int r) { return min(1, 0, sz - 1, l, r); }

  void update(int pos, int val) { update(1, 0, sz - 1, pos, val); }
};

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;

  SegmentTree st(arr);
  for (int i = 0; i < q; i++) {
    int x;
    int l, r;
    cin >> x >> l >> r;
    if (x == 1)
      st.update(--l, r);
    else if (x == 2)
      cout << st.min(--l, --r) << '\n';
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
