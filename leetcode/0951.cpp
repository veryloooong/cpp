#include <cstdint>
#include <iostream>

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
public:
  bool flipEquiv(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr)
      return true;

    if (root1 == nullptr || root2 == nullptr)
      return false;

    if (root1->val != root2->val)
      return false;

    bool check1 = flipEquiv(root1->left, root2->left) &&
                  flipEquiv(root1->right, root2->right);
    bool check2 = flipEquiv(root1->left, root2->right) &&
                  flipEquiv(root1->right, root2->left);

    return check1 || check2;
  }
};

int main() {
  TreeNode e(4);
  TreeNode d(2);
  TreeNode c(3);
  TreeNode b(1, &d, &e);
  TreeNode a1(0, &b, &c);
  TreeNode a2(0, nullptr, &c);

  cout << Solution().flipEquiv(&a1, &a2) << endl;
}