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

  TreeNode *recurse(std::vector<int> const &preorder,
                    std::vector<int> const &postorder, int l, int r, int &i) {
    const int n = preorder.size();
    if (i >= n || l > r)
      return nullptr;

    TreeNode *root = new TreeNode(preorder[i++]);
    if (l < r) {
      int j = l;
      while (j <= r && preorder[i] != postorder[j])
        j++;
      root->left = recurse(preorder, postorder, l, j, i);
      root->right = recurse(preorder, postorder, j + 1, r - 1, i);
    }

    return root;
  }

public:
  TreeNode *constructFromPrePost(std::vector<int> &preorder,
                                 std::vector<int> &postorder) {
    int i = 0;
    return recurse(preorder, postorder, 0, preorder.size() - 1, i);
  }
};