#include <algorithm>
#include <vector>

class Solution {
public:
  int stoneGameII(std::vector<int> &piles) {
    const int n = piles.size();

    std::vector<std::vector<int>> dp(n, std::vector<int>(n + 1, 0));
    std::vector<int> suffixSums(n);
    suffixSums[n - 1] = piles[n - 1];

    for (int i = n - 2; i >= 0; i--) {
      suffixSums[i] = suffixSums[i + 1] + piles[i];
    }

    for (int i = n - 1; i >= 0; i--) {
      for (int m = 1; m <= n; m++) {
        if (i + 2 * m >= n)
          dp[i][m] = suffixSums[i];
        else
          for (int x = 1; x <= 2 * m; x++)
            dp[i][m] =
                std::max(dp[i][m], suffixSums[i] - dp[i + x][std::max(m, x)]);
      }
    }

    return dp[0][1];
  }
};