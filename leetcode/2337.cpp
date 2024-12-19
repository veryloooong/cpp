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
  bool canChange(std::string start, std::string target) {
    const size_t n = start.length();
    size_t start_index = 0, target_index = 0;

    while (start_index < n && target_index < n) {
      // skip _
      while (start_index < n && start[start_index] == '_')
        start_index++;
      while (target_index < n && target[target_index] == '_')
        target_index++;

      // check if end of string
      if (start_index == n || target_index == n)
        return start_index == n && target_index == n;

      // check L/R
      if (start[start_index] != target[target_index])
        return false;
      if (start[start_index] == 'L' && start_index < target_index)
        return false;
      if (start[start_index] == 'R' && start_index > target_index)
        return false;

      start_index++;
      target_index++;
    }

    return true;
  }
};