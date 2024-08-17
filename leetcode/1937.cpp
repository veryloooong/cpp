#include <algorithm>
#include <vector>

class Solution {
public:
  long long maxPoints(std::vector<std::vector<int>> &points) {
    int m = points.size();
    int n = points[0].size();

    std::vector<std::vector<long long>> dp(m, std::vector<long long>(n));
    for (int i = 0; i < n; i++) {
      dp[0][i] = points[0][i];
    }

    for (int i = 1; i < m; i++) {
      std::vector<long long> fromLeft(n, 0), fromRight(n, 0);
      long long current = 0;
      for (int j = 0; j < n; j++) {
        current = std::max(current - 1, dp[i - 1][j]);
        fromLeft[j] = current;
      }
      current = 0;
      for (int j = n - 1; j >= 0; j--) {
        current = std::max(current - 1, dp[i - 1][j]);
        fromRight[j] = current;
      }

      for (int j = 0; j < n; j++)
        dp[i][j] = std::max(fromLeft[j], fromRight[j]) + points[i][j];
    }

    auto lastRow = dp[m - 1];
    return *std::max_element(lastRow.begin(), lastRow.end());
  }
};