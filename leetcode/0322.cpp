#include <algorithm>
#include <cstdint>
#include <ranges>
#include <string>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  typedef int32_t i32;
  typedef uint32_t u32;
  typedef int64_t i64;
  typedef uint64_t u64;

public:
  int coinChange(std::vector<int> &coins, int amount) {
    if (amount == 0)
      return 0;

    std::vector<int> dp(amount + 1, INT16_MAX);

    dp[0] = 0;
    for (int c : coins | std::ranges::views::filter(
                             [&amount](int c) { return c <= amount; }))
      dp[c] = 1;

    for (int i = std::ranges::min(coins); i <= amount; i++) {
      for (const int &c : coins) {
        if (i - c >= 0)
          dp[i] = std::min(dp[i], 1 + dp[i - c]);
      }
    }

    return dp.back() == INT16_MAX ? -1 : dp.back();
  }
};