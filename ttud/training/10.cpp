#include <algorithm>
#include <chrono>
#include <cstdint>
#include <fstream>
#include <functional>
#include <iostream>
#include <unordered_map>
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

  void update(int v, int lb, int rb, int x, int val) {
    if (lb >= rb)
      tree[v] = val;
    else {
      int m = (lb + rb) / 2;
      if (x <= m)
        update(2 * v, lb, m, x, val);
      else
        update(2 * v + 1, m + 1, rb, x, val);
      tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }
  }

  int query(int v, int lb, int rb, int x, int y) {
    if (x > y)
      return 0;
    if (lb == x && rb == y)
      return tree[v];

    int m = (lb + rb) / 2;
    return max(query(2 * v, lb, m, x, min(y, m)),
               query(2 * v + 1, m + 1, rb, max(x, m + 1), y));
  }

public:
  SegmentTree(int sz) : sz(sz), tree(4 * sz + 4) {}

  // update LIS ending with value x = val length
  void update(int x, int val) { update(1, 1, sz, x, val); }

  // query max LIS with value in [x, y]
  int query(int x, int y) { return query(1, 1, sz, x, y); }
};

void solve() {
  int n;
  cin >> n;
  vector<i64> arr(n);
  for (auto &x : arr)
    cin >> x;

  vector<i64> sorted(arr);
  sort(sorted.begin(), sorted.end(), greater<i64>());
  unordered_map<int, int> compress;
  int at = 0;
  for (int i : sorted) {
    if (!compress.count(i))
      compress[i] = ++at;
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] & 1)
      arr[i] = 2 * compress[arr[i]] + 1;
    else
      arr[i] = 2 * compress[arr[i]];
  }

  SegmentTree even(2 * n + 2), odd(2 * n + 2);

  for (int v : arr) {
    int res = 0;
    if (v & 1) {
      res = even.query(1, v - 1);
      odd.update(v, res + 1);
    } else {
      res = odd.query(1, v - 1);
      even.update(v, res + 1);
    }
  }

  cout << max(even.query(1, 2 * n + 1), odd.query(1, 2 * n + 1)) << '\n';
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

  int t;
  cin >> t;
  while (t--)
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
