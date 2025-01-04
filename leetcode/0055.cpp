#include <cstdint>
#include <set>
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
  bool canJump(std::vector<int> &nums) {
    const int n = nums.size();
    int goal = n - 1;
    for (int i = n - 2; i >= 0; i--) {
      if (i + nums[i] >= goal)
        goal = i;
    }
    return goal == 0;
  }
};