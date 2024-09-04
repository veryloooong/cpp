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
public:
  std::vector<int> postorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }

    std::vector<int> leftSubtree = postorderTraversal(root->left);
    std::vector<int> rightSubtree = postorderTraversal(root->right);

    std::vector<int> res{};
    res.reserve(leftSubtree.size() + rightSubtree.size() + 1);

    res.insert(res.end(), leftSubtree.begin(), leftSubtree.end());
    res.insert(res.end(), rightSubtree.begin(), rightSubtree.end());
    res.insert(res.end(), root->val);

    return res;
  }
};