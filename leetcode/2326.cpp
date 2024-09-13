#include <utility>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
  using coord_t = std::pair<int, int>;

public:
  std::vector<std::vector<int>> spiralMatrix(int m, int n, ListNode *head) {
    const std::vector<coord_t> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    std::vector<std::vector<int>> matrix(m, std::vector<int>(n, -1));

    int x = 0, y = 0;
    int currentDir = 0;

    for (ListNode *current = head; current; current = current->next) {
      matrix[x][y] = current->val;

      const auto [dx, dy] = dirs[currentDir];
      if (x + dx < 0 || x + dx >= m || y + dy < 0 || y + dy >= n ||
          matrix[x + dx][y + dy] != -1) {
        currentDir = (currentDir + 1) % 4;
      }

      x = x + dirs[currentDir].first;
      y = y + dirs[currentDir].second;
    }

    return matrix;
  }
};