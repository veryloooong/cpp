#include <algorithm>
#include <cstdint>
#include <iterator>
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
  int rob(std::vector<int> &nums) {
    std::vector<int> dp(nums.begin(), nums.end());
    int cur = dp[0];
    for (size_t i = 2; i < nums.size(); i++) {
      dp[i] = nums[i] + cur;
      cur = std::max(cur, dp[i - 1]);
    }

    return std::max(dp.back(), *std::prev(dp.end(), 2));
  }
};