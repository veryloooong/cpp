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
  int longestOnes(std::vector<int> &nums, int k) {
    int lhs = 0, rhs = 0, zeros = 0, n = nums.size(), best = 0;
    while (rhs < n) {
      zeros += (nums[rhs] == 0);
      while (lhs <= rhs && zeros > k) {
        zeros -= (nums[lhs++] == 0);
      }
      best = std::max(best, rhs - lhs + 1);
      rhs++;
    }
    return best;
  }
};