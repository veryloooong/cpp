#include <cstdint>
#include <string>
#include <unordered_set>
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
};

class FindElements {
private:
  std::unordered_set<int> values;

  void recurse(TreeNode *node, int val) {
    if (node == nullptr)
      return;

    values.insert(val);
    node->val = val;
    recurse(node->left, 2 * val + 1);
    recurse(node->right, 2 * val + 2);
  }

public:
  FindElements(TreeNode *root) { recurse(root, 0); }

  bool find(int target) { return values.contains(target); }
};