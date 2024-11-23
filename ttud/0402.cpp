#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int MOD = 1e9 + 7;

int main() {
  int n, k1, k2;
  cin >> n >> k1 >> k2;

  vector<int> dp(n + 1, 0); // dp[i] = number of ways to schedule i days
  dp[0] = 1;                // base case schendule 0 days in 1 way
  dp[1] = 1;                // schedule 1 day as work

  for (int i = 2; i <= n; i++) {
    for (int j = k1 + 1; j <= k2 + 1; j++) {
      // check if we can schedule j working days on day i
      if (i - j >= 0) {
        dp[i] = (dp[i] + dp[i - j]) % MOD;
      }
    }
  }

  long long ans = 0;
  for (int i = max(0, n - k2); i <= max(0, n - k1); i++)
    ans += dp[i];

  ans += dp[n];

  cout << ans << endl;
}