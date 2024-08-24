#include <algorithm>
#include <string>
#include <vector>

class Solution {
  const int MAX_STRLEN = 101;

public:
  int strangePrinter(std::string s) {
    std::vector<char> nondupes{};
    for (const char &c : s) {
      if (nondupes.empty() || c != nondupes.back())
        nondupes.push_back(c);
    }
    int n = nondupes.size();

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, MAX_STRLEN));
    for (int i = 0; i < n; i++)
      dp[i][i] = 1;

    for (int len = 2; len <= n; len++) {
      for (int start = 0; start <= n - len; start++) {
        int currentChar = nondupes[start];

        int end = start + len - 1;
        dp[start][end] = dp[start + 1][end] + 1;

        for (int nextCharIdx = start + 1; nextCharIdx <= end; nextCharIdx++) {
          if (nondupes[nextCharIdx] == currentChar) {
            dp[start][end] = std::min(
                dp[start][end],
                dp[start][nextCharIdx - 1] +
                    (nextCharIdx + 1 <= end ? dp[nextCharIdx + 1][end] : 0));
          }
        }
      }
    }

    return dp[0][n - 1];
  }
};