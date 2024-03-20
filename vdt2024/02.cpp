#include <bits/stdc++.h>

using namespace std;

constexpr size_t MOD = 1e9 + 7;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;

  int n = s.length();
  vector<vector<vector<int>>> dp(n + 5,
                                 vector<vector<int>>(n + 5, vector<int>(6)));

  for (int i = n; i >= 1; --i) {
    for (int j = i; j <= n; ++j) {
      dp[i][j][0] = 1;
      dp[i][j][1] = j - i + 1;

      for (int k = 3; k <= 5; k += 2) {
        int prev =
            ((dp[i][j - 1][k] + dp[i + 1][j][k]) % MOD - dp[i + 1][j - 1][k]) %
            MOD;
        dp[i][j][k] =
            ((s[i - 1] == s[j - 1]) * dp[i + 1][j - 1][k - 2] + prev) % MOD;
      }
    }
  }

  cout << dp[1][n][5] << '\n';

  return 0;
}