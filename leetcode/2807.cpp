#include <numeric>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *insertGreatestCommonDivisors(ListNode *head) {
    ListNode *current = head;
    ListNode *prev = nullptr;

    for (current = head->next, prev = head; current;
         prev = current, current = current->next) {
      ListNode *nextNode = new ListNode(std::gcd(current->val, prev->val));
      prev->next = nextNode;
      nextNode->next = current;
    }

    return head;
  }
};
