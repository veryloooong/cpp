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
  int longestMonotonicSubarray(std::vector<int> &nums) {
    int best = 1;
    int inc = 1, dec = 1;

    for (int i = 1, n = nums.size(); i < n; i++) {
      if (nums[i] > nums[i - 1]) {
        inc++;
        dec = 1;
      } else if (nums[i] < nums[i - 1]) {
        dec++;
        inc = 1;
      } else {
        inc = 1;
        dec = 1;
      }
      best = std::max({best, inc, dec});
    }

    return best;
  }
};