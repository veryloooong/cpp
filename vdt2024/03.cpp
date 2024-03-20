#include <bits/stdc++.h>

using namespace std;

constexpr size_t MAXN = 1002;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int x, n;
  cin >> x;
  int min_p = 1003;
  cin >> n;
  vector<int> sizes(n);
  vector<int> dp(MAXN);

  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    sizes[i] = p;
    min_p = min(min_p, p);
    dp[p] = 1;
  }

  if (min_p > x) {
    cout << -1 << '\n';
  } else if (dp[x]) {
    cout << 1 << '\n';
  } else {
    for (int i = min_p; i <= x; ++i) {
      if (dp[i])
        continue;
      int best = INT_MAX;
      // bool empty = true;
      for (int j = 0; j < n; ++j) {
        int prev = max(i - sizes[j], 0);
        // if (dp[prev] != 0) {
        //   empty = false;
        // }
        if (dp[prev] == 0)
          continue;
        best = min(best, 1 + dp[prev]);
      }
      dp[i] = (best == INT_MAX ? 0 : best);
      // dp[i] = (empty ? 0 : best);
    }
    cout << (dp[x] > 0 ? dp[x] : -1) << '\n';
  }

  return 0;
}