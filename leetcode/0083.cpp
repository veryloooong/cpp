#include <cstdint>

using namespace std;

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
private:
  typedef int32_t i32;
  typedef uint32_t u32;
  typedef int64_t i64;
  typedef uint64_t u64;

public:
  ListNode *deleteDuplicates(ListNode *head) {
    int current_value;
    int previous_value = -101;
    ListNode *current_node = nullptr;
    ListNode *new_head = nullptr;

    while (head) {
      current_value = head->val;
      head = head->next;

      if (current_value != previous_value) {
        ListNode *node = new ListNode(current_value);

        if (!current_node) {
          new_head = node;
          current_node = new_head;
        } else {
          current_node->next = node;
          current_node = current_node->next;
        }
      }

      previous_value = current_value;
    }

    return new_head;
  }
};