#include <algorithm>
#include <cstdint>
#include <functional>
#include <queue>
#include <string>
#include <utility>
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

public:
  int maxTwoEvents(std::vector<std::vector<int>> &events) {
    std::sort(events.begin(), events.end());
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<>>
        pq;

    int current = 0, ans = 0;
    for (const std::vector<int> &event : events) {
      while (!pq.empty() && pq.top().first < event[0]) {
        current = std::max(current, pq.top().second);
        pq.pop();
      }

      ans = std::max(ans, current + event[2]);
      pq.push({event[1], event[2]});
    }

    return ans;
  }
};