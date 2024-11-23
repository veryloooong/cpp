#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int solve(int N, int T, int D, vector<int> &a, vector<int> &t) {
  vector<vector<int>> dp(N, vector<int>(T + 1, INT_MIN));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= T; j++) {
      if (t[i] <= j) {
        dp[i][j] = a[i];
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= T; j++) {
      if (dp[i][j] != INT_MIN) {
        for (int k = 1; k <= D; k++) {
          if (i + k < N) {
            int new_time = j + t[i + k];
            if (new_time <= T) {
              dp[i + k][new_time] =
                  max(dp[i + k][new_time], dp[i][j] + a[i + k]);
            }
          }
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= T; j++) {
      ans = max(ans, dp[i][j]);
    }
  }

  return ans;
}

int main() {
  int N, T, D;
  cin >> N >> T >> D;

  vector<int> a(N);
  vector<int> t(N);

  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> t[i];
  }

  cout << solve(N, T, D, a, t) << endl;
}