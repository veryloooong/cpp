#include <algorithm>
#include <chrono>
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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  if (n == 1)
    cout << a[0] << endl;
  else if (n == 2)
    cout << a[0] + a[1] << endl;

  vector<int> dp(n);
  dp[0] = a[0];
  dp[1] = a[0] + a[1];
  dp[2] = max({dp[1], a[0] + a[2], a[1] + a[2]});
  for (int i = 3; i < n; i++) {
    // bo i hoac bo i - 1 hoac bo i - 2 va lay 2 cai gan nhat
    dp[i] = max({dp[i - 1], dp[i - 2] + a[i], dp[i - 3] + a[i - 1] + a[i]});
  }
  cout << dp.back() << endl;
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

/*
 * "uuuuuuuuuuuuuuu" - Ceres Fauna (2021 - 2025)
 * imissfauna.com
 */
