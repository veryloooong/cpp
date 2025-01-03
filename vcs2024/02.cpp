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

void solve() {
  int n;
  cin >> n;

  vector<vector<i64>> dp(n + 1, vector<i64>(5)); // a e i o u

  for (int i = 0; i <= 4; i++)
    dp[1][i] = 1;

  for (int len = 2; len <= n; len++) {
    dp[len][0] +=
        ((dp[len - 1][1] + dp[len - 1][2]) % MOD + dp[len - 1][4]) % MOD;
    dp[len][1] += (dp[len - 1][0] + dp[len - 1][2]) % MOD;
    dp[len][2] += (dp[len - 1][1] + dp[len - 1][3]) % MOD;
    dp[len][3] += (dp[len - 1][2]) % MOD;
    dp[len][4] += (dp[len - 1][2] + dp[len - 1][3]) % MOD;
  }

  i64 ans = 0;
  for (int i = 0; i < 5; i++) {
    ans = (ans + dp[n][i]) % MOD;
  }
  cout << ans;
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
