struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
  bool isSubPath(ListNode *head, TreeNode *root) {
    if (root == nullptr)
      return false;
    if (isSame(head, root))
      return true;
    return isSubPath(head, root->left) || isSubPath(head, root->right);
  }

private:
  bool isSame(ListNode *listNode, TreeNode *treeNode) {
    // end of list
    if (listNode == nullptr)
      return true;

    if (treeNode == nullptr || listNode->val != treeNode->val)
      return false;

    return isSame(listNode->next, treeNode->left) ||
           isSame(listNode->next, treeNode->right);
  }
};