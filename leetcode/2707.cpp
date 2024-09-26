#include <numeric>
#include <string>
#include <string_view>
#include <vector>

class Solution {
public:
  int minExtraChar(std::string s, std::vector<std::string> &dictionary) {
    // dp[i]: break up s.substr(0, i);
    std::vector<int> dp(s.size() + 1, 0);
    std::iota(dp.begin(), dp.end(), 0);

    std::string_view sv{};
    int lastIndex = 0;
    for (int i = 1; i <= s.size(); i++) {
    }

    return dp[s.size()];
  }
};