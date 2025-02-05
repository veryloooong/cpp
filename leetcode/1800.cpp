#include <algorithm>
#include <cstdint>
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
  int maxAscendingSum(std::vector<int> &nums) {
    int ans = *std::max_element(nums.begin(), nums.end());
    int cur = nums[0];

    for (int i = 1, n = nums.size(); i < n; i++) {
      if (nums[i] <= nums[i - 1])
        cur = nums[i];
      else
        cur += nums[i];

      ans = std::max(ans, cur);
    }

    return ans;
  }
};