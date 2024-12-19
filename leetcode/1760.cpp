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

  int countOperationsTo(const std::vector<int> &nums, int m) {
    int cnt = 0;
    for (const int &x : nums) {
      cnt += (x - 1) / m;
    }

    return cnt;
  }

public:
  int minimumSize(std::vector<int> &nums, int maxOperations) {
    int lhs = 1, rhs = *std::max_element(nums.begin(), nums.end());

    while (lhs < rhs) {
      const int m = lhs + (rhs - lhs) / 2;
      if (countOperationsTo(nums, m) <= maxOperations)
        rhs = m;
      else
        lhs = m + 1;
    }

    return lhs;
  }
};