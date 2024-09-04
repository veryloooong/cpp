#include <vector>

class Node {
public:
  int val;
  std::vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, std::vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
public:
  std::vector<int> postorder(Node *root) {
    if (root == nullptr) {
      return {};
    }

    if (root->children.size() == 0) {
      return {root->val};
    }

    std::vector<int> ans{};
    ans.reserve(10000);
    for (auto &child : root->children) {
      std::vector<int> traverse = postorder(child);
      ans.insert(ans.end(), traverse.begin(), traverse.end());
    }

    ans.push_back(root->val);

    return ans;
  }
};