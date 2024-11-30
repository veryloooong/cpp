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
  std::vector<int> resultsArray(std::vector<int> &nums, int k) {
    const int n = nums.size();
    std::vector<int> ans{};
    int lhs = 0;

    for (int i = 0; i < n; i++) {
      if (i > 0 && nums[i] - nums[i - 1] != 1)
        lhs = i;

      if (i >= k - 1)
        ans.push_back(i - lhs + 1 >= k ? nums[i] : -1);
    }

    return ans;
  }
};