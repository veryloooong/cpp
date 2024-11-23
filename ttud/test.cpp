#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, L1, L2;
  cin >> N >> L1 >> L2;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  vector<int> dp(N, 0);
  dp[0] = a[0];

  int ans = 0;
  int max_current_window = 0;
  int lhs = 0;

  for (int i = 1; i < N; i++) {
    dp[i] = a[i];

    if (i - lhs > L2) {
      if (max_current_window == dp[lhs] || max_current_window == 0) {
        max_current_window =
            *max_element(dp.begin() + lhs + 1, dp.begin() + i + 1);
      }
      lhs++;
    }

    dp[i] = max(dp[i], max_current_window + a[i]);

    ans = max(ans, dp[i]);
  }

  cout << ans << '\n';
}