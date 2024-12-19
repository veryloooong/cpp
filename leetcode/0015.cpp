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
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    const int n = nums.size();
    if (n < 3)
      return {{}};
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> ans{};

    for (int i = 0; i < n - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int lhs = i + 1;
      int rhs = n - 1;
      while (lhs < rhs) {
        const int sum = nums[i] + nums[lhs] + nums[rhs];
        if (sum > 0)
          rhs--;
        else if (sum < 0)
          lhs++;
        else {
          ans.push_back({nums[i], nums[lhs++], nums[rhs--]});
          while (lhs < rhs && nums[lhs] == nums[lhs - 1])
            lhs++;
          while (lhs < rhs && nums[rhs] == nums[rhs + 1])
            rhs--;
        }
      }
    }

    return ans;
  }
};