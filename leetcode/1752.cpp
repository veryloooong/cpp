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
  bool check(std::vector<int> &nums) {
    for (int i = 0, n = nums.size(); i < n; i++) {
      if (std::is_sorted(nums.begin(), nums.end()))
        return true;
      std::rotate(nums.begin(), nums.begin() + 1, nums.end());
    }

    return false;
  }
};