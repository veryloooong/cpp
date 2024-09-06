#include <unordered_set>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *modifiedList(std::vector<int> &nums, ListNode *head) {
    std::unordered_set<int> checks(nums.begin(), nums.end());
    ListNode stack_temp(0, head);
    ListNode *current = head;
    ListNode *previous = &stack_temp;

    while (current != nullptr) {
      if (checks.find(current->val) != checks.end()) {
        previous->next = current->next;
      } else {
        previous = previous->next;
      }

      current = current->next;
    }

    return stack_temp.next;
  }
};