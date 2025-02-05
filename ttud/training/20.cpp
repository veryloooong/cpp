#include <algorithm>
#include <chrono>
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
const char *expected = "expected.txt";

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
  int sz;
  vector<int> tree;

  void build(vector<int> &arr, int v, int lb, int rb) {
    if (lb == rb)
      tree[v] = arr[lb];
    else {
      int m = (lb + rb) / 2;
      build(arr, 2 * v, lb, m);
      build(arr, 2 * v + 1, m + 1, rb);
      tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }
  }

  void build(vector<int> &arr) { build(arr, 1, 0, sz - 1); }

  int query(int v, int lb, int rb, int l, int r) {
    if (l > r)
      return INT_MIN;
    if (lb == l && rb == r)
      return tree[v];
    int m = (lb + rb) / 2;
    return max(query(2 * v, lb, m, l, min(r, m)),
               query(2 * v + 1, m + 1, rb, max(l, m + 1), r));
  }

  void update(int v, int lb, int rb, int key, int val) {
    if (lb == rb)
      tree[v] = val;
    else {
      int m = (lb + rb) / 2;
      if (key <= m)
        update(2 * v, lb, m, key, val);
      else
        update(2 * v + 1, m + 1, rb, key, val);
      tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }
  }

public:
  SegmentTree() {}

  SegmentTree(vector<int> &arr) : sz(arr.size()), tree(4 * arr.size()) {
    build(arr);
  }

  void update(int key, int val) { update(1, 0, sz - 1, key, val); }

  int query(int l, int r) { return query(1, 0, sz - 1, l, r); }
};

void solve() {
  int n, l1, l2;
  cin >> n >> l1 >> l2;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  SegmentTree st(a);

  for (int i = l1; i < n; i++) {
    st.update(i, st.query(max(0, i - l2), i - l1) + a[i]);
  }

  cout << st.query(0, n - 1);
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
  cerr << boolalpha;

#ifndef ONLINE_JUDGE
  auto start = chrono::high_resolution_clock::now();
#endif

  solve();

#ifndef ONLINE_JUDGE
  auto end = chrono::high_resolution_clock::now();
  auto elapsed = end - start;
  cerr << "runtime: "
       << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count()
       << " ms" << endl;
#endif

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */
