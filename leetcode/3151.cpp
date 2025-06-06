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
  bool isArraySpecial(std::vector<int> &nums) {
    const int n = nums.size();
    for (int i = 1; i < n; i++) {
      if (!((nums[i] ^ nums[i - 1]) & 1))
        return false;
    }

    return true;
  }
};