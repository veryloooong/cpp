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
  std::string findDifferentBinaryString(std::vector<std::string> &nums) {
    std::string ans;

    for (int i = 0, n = nums.size(); i < n; i++) {
      std::string &s = nums[i];
      if (s[i] == '0')
        ans += '1';
      else
        ans += '0';
    }

    return ans;
  }
};