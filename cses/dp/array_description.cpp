#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;

constexpr ll MOD = 1e9 + 7; // NOLINT

static constexpr ull ct_sqrt(ull res, ull l, ull r) {
  if (l == r) {
    return r;
  } else {
    const auto mid = (r + l) / 2;

    if (mid * mid >= res) {
      return ct_sqrt(res, l, mid);
    } else {
      return ct_sqrt(res, mid + 1, r);
    }
  }
}

// Compile-time square root
static constexpr ull ct_sqrt(ull res) { return ct_sqrt(res, 1, res); } // NOLINT

// Binary exponential
constexpr ull expo(ull base, ull exponent, ull mod) {
  ull result = 1;

  while (exponent > 0) {
    if (exponent & 1) {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    exponent >>= 1;
  }
  return result;
}

constexpr ull MAXN = 1e5;
constexpr ull MAXM = 100;

ll dp[MAXN + 1][MAXM + 2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;

  ll ans = 0;

  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  /** every col in 1..n is the index
   *  every row in 1..m is the value in that arr
   */

  if (arr[0] == 0) {
    for (int i = 1; i <= m; ++i)
      dp[1][i] = 1;
  } else {
    dp[1][arr[0]] = 1;
  }

  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= m; ++j)
      dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;

    if (arr[i - 1] != 0)
      for (int j = 0; j <= m; ++j)
        if (j != arr[i - 1])
          dp[i][j] = 0;
  }

  for (int i = 1; i <= m; ++i) {
    ans = (ans + dp[n][i]) % MOD;
  }

  cout << ans << endl;

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */