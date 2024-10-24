#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

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
  void changeChildren(TreeNode *current, const vector<long long> &levelSum,
                      size_t level) {
    if (current == nullptr)
      return;
    if (level >= levelSum.size())
      return;

    long long s = 0;
    if (current->left)
      s += current->left->val;
    if (current->right)
      s += current->right->val;

    if (current->left)
      current->left->val = levelSum[level] - s;
    if (current->right)
      current->right->val = levelSum[level] - s;

    if (current->left)
      changeChildren(current->left, levelSum, level + 1);
    if (current->right)
      changeChildren(current->right, levelSum, level + 1);
  }

public:
  TreeNode *replaceValueInTree(TreeNode *root) {
    vector<long long> levelSum{};
    queue<TreeNode *> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
      int levelSize = nodes.size();
      long long current = 0;
      for (int i = 0; i < levelSize; i++) {
        TreeNode *node = nodes.front();
        nodes.pop();
        current += node->val;
        if (node->left)
          nodes.push(node->left);
        if (node->right)
          nodes.push(node->right);
      }
      levelSum.push_back(current);
    }

    root->val = 0;
    changeChildren(root, levelSum, 1);

    std::for_each(levelSum.begin(), levelSum.end(),
                  [](int x) { cerr << x << ' '; });

    return root;
  }
};