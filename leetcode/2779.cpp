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
  int maximumBeauty(std::vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());
    int lhs = 0, rhs = 0, n = nums.size();

    int ans = 1;

    while (rhs < n) {
      while (lhs < rhs && nums[rhs] - nums[lhs] > 2 * k)
        lhs++;
      ans = std::max(ans, rhs - lhs + 1);
      rhs++;
    }

    return ans;
  }
};