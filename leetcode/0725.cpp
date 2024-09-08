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
  std::vector<ListNode *> splitListToParts(ListNode *head, int k) {
    int listLen = 0;
    for (ListNode *current = head; current != nullptr;
         current = current->next, listLen++)
      ;

    int partLen = listLen / k;
    int firstExtra = listLen % k;

    std::vector<ListNode *> parts{};

    int currentPartLen = 0;
    ListNode *currentPartHead = nullptr;
    ListNode *tmp = nullptr;

    for (ListNode *current = head; current != nullptr;
         current = current->next, currentPartLen++) {
      if (currentPartLen == partLen + (parts.size() < firstExtra)) {
        currentPartLen = 0;
        tmp->next = nullptr;
        parts.push_back(currentPartHead);
        currentPartHead = current;
        tmp = currentPartHead;
      } else {
        if (currentPartHead == nullptr) {
          currentPartHead = current;
          tmp = currentPartHead;
        } else {
          tmp->next = current;
          tmp = tmp->next;
        }
      }
    }

    parts.push_back(currentPartHead);

    while (parts.size() < k) {
      parts.push_back(nullptr);
    }

    return parts;
  }
};