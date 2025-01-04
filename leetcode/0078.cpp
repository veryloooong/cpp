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
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    std::vector<std::vector<int>> ans{};

    for (int i = 0, n = 1 << nums.size(); i < n; i++) {
      std::vector<int> subset;
      for (size_t j = 0; j < nums.size(); j++) {
        if ((1 << j) & i)
          subset.push_back(nums[j]);
      }
      ans.push_back(subset);
    }

    return ans;
  }
};