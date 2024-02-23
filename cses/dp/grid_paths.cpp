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
constexpr ull expo(ull base, ull exponent) {
  ull result = 1;

  while (exponent > 0) {
    if (exponent & 1) {
      result = (result * base) % MOD;
    }
    base = (base * base) % MOD;
    exponent >>= 1;
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<string> grid(n);
  vector<vector<ll>> dp(n, vector<ll>(n));

  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  dp[0][0] = (grid[0][0] == '.');

  function<char(int, int)> point = [&](int i, int j) {
    if (i < 0 || j < 0) {
      return '\0';
    }
    return grid[i][j];
  };

  function<ll(int, int)> getdp = [&](int i, int j) {
    if (i < 0 || j < 0)
      return 0l;
    return dp[i][j];
  };

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (point(i, j) == '.') {
        if (point(i - 1, j) == '.')
          dp[i][j] += getdp(i - 1, j);
        if (point(i, j - 1) == '.')
          dp[i][j] += getdp(i, j - 1);
        dp[i][j] %= MOD;
      }
    }
  }

  cout << dp[n - 1][n - 1] << endl;

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */