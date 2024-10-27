#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <vector>

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

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
  unordered_map<int, size_t> nodeHeight{};
  unordered_map<int, size_t> maxHeightWithoutNode{};

  size_t treeHeight(TreeNode *root) {
    if (root == nullptr)
      return 0;

    if (auto it = nodeHeight.find(root->val); it != nodeHeight.end()) {
      return it->second;
    }

    size_t height = 1 + max(treeHeight(root->left), treeHeight(root->right));
    return nodeHeight[root->val] = height;
  }

  void findMaxHeight(TreeNode *root, size_t currentDepth,
                     size_t currentMaxHeight) {
    if (root == nullptr)
      return;

    maxHeightWithoutNode[root->val] = currentMaxHeight;

    // go find left
    findMaxHeight(
        root->left, currentDepth + 1,
        max(currentMaxHeight, currentDepth + treeHeight(root->right)));

    // go find right
    findMaxHeight(root->right, currentDepth + 1,
                  max(currentMaxHeight, currentDepth + treeHeight(root->left)));
  }

public:
  vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
    vector<int> ans{};

    findMaxHeight(root, 0, 0);

    for (const int &x : queries)
      ans.push_back(maxHeightWithoutNode[x]);

    return ans;
  }
};