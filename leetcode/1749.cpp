#include <algorithm>
#include <climits>
#include <cstdint>
#include <cstdlib>
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
  int maxAbsoluteSum(std::vector<int> &nums) {
    int min = 0;
    int max = 0;
    int current_min = 0;
    int current_max = 0;
    for (int num : nums) {
      current_min = std::min(0, current_min + num);
      current_max = std::max(0, current_max + num);
      min = std::min(min, current_min);
      max = std::max(max, current_max);
    }

    return std::max(std::abs(min), std::abs(max));
  }
};