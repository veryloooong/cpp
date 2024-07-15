#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {};
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {};
};

class Solution {
public:
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    TreeNode *root = nullptr;

    unordered_map<int, TreeNode *> nodes{};
    unordered_set<int> children{};

    for (auto &d : descriptions) {
      int parent = d[0];
      int child = d[1];
      int left = d[2];

      if (!nodes[parent])
        nodes[parent] = new TreeNode(parent);
      if (!nodes[child])
        nodes[child] = new TreeNode(child);

      if (left)
        nodes[parent]->left = nodes[child];
      else
        nodes[parent]->right = nodes[child];

      children.insert(child);
    }

    for (auto &&[val, node] : nodes) {
      if (children.find(val) == children.end())
        root = node;
    }

    return root;
  }
};

int main() {
  Solution s = Solution();

  vector<vector<int>> descriptions = {
      {20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};

  TreeNode *root = s.createBinaryTree(descriptions);
}