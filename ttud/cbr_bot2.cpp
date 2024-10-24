#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 12;
const int MAX_K = 5;
const int MAX_Q = 50;
const int INF = 1e9;

int n, K, Q;
int d[MAX_N + 1];
int c[MAX_N + 1][MAX_N + 1];
int dp[MAX_N + 1][1 << MAX_N][MAX_K + 1];

int solve(int i, int j, int k) {
  if (k == 0) {
    return (j == (1 << n) - 1) ? 0 : INF;
  }
  if (dp[i][j][k] != -1) {
    return dp[i][j][k];
  }
  int ans = INF;
  for (int p = 0; p < n; p++) {
    if (!(j & (1 << p))) {
      int load = d[p + 1];
      int next_j = j | (1 << p);
      int next_k = k;
      if (load > Q) {
        continue;
      }
      if (load == Q) {
        next_k--;
        load = 0;
      }
      int next_ans = solve(p + 1, next_j, next_k) + c[i][p + 1];
      ans = min(ans, next_ans);
    }
  }
  return dp[i][j][k] = ans;
}

int main() {
  cin >> n >> K >> Q;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      cin >> c[i][j];
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0, K) << endl;
  return 0;
}