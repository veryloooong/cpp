#include <algorithm>
#include <functional>
#include <queue>
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
  long long kthLargestLevelSum(TreeNode *root, int k) {
    std::queue<TreeNode *> nodes{};
    std::vector<long long> sums{};
    nodes.push(root);
    while (!nodes.empty()) {
      int levelSize = nodes.size();
      long long levelSum = 0;
      for (int i = 0; i < levelSize; i++) {
        TreeNode *node = nodes.front();
        nodes.pop();
        levelSum += node->val;
        if (node->left) {
          nodes.push(node->left);
        }
        if (node->right) {
          nodes.push(node->right);
        }
      }
      sums.push_back(levelSum);
    }

    std::sort(sums.begin(), sums.end(), std::greater<>());
    if (k > sums.size())
      return -1;
    else
      return sums[k - 1];
  }
};