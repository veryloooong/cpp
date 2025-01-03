#include <algorithm>
#include <bitset>
#include <chrono>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <numeric>
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

int num_of_or_sums_less_than_m(vector<int> &arr, int m) {
  int ans = 0, n = arr.size();

  vector<int> bitmask_freq(16);
  bitset<16> bitmask;

  auto bitmask_set_func = [&bitmask, &bitmask_freq](int x) {
    for (int i = 0; i < 16; i++)
      if (x & (1 << i) && ++bitmask_freq[i] == 1)
        bitmask.set(i);
  };

  auto bitmask_rmv_func = [&bitmask, &bitmask_freq](int x) {
    for (int i = 0; i < 16; i++)
      if (x & (1 << i) && --bitmask_freq[i] == 0)
        bitmask.reset(i);
  };

  for (int lhs = 0, rhs = 0; rhs < n; rhs++) {
    bitmask_set_func(arr[rhs]);
    while (lhs <= rhs && (int)bitmask.to_ullong() >= m) {
      bitmask_rmv_func(arr[lhs++]);
    }
    ans += rhs - lhs + 1;
  }

  return ans;
}

void solve() {
  int n, k;
  cin >> n;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;
  cin >> k;
  int cnt = n * (n + 1) / 2 - k + 1;

  int lo = *min_element(arr.begin(), arr.end()),
      hi = accumulate(arr.begin(), arr.end(), 0,
                      [](int acc, int x) { return acc | x; });

  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (num_of_or_sums_less_than_m(arr, mid) < cnt) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }

  cout << lo - 1;
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
