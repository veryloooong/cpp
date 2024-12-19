#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
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
  long long findScore(std::vector<int> &nums) {
    using couple_t = std::pair<int, size_t>;
    std::priority_queue<couple_t, std::vector<couple_t>, std::greater<>> pq;
    const size_t n = nums.size();
    for (size_t i = 0; i < n; i++) {
      pq.push({nums[i], i});
    }
    i64 ans = 0;
    std::vector<bool> marked(n);
    while (!pq.empty()) {
      const auto [num, i] = pq.top();
      pq.pop();
      if (marked[i])
        continue;
      ans += num;
      marked[i] = true;
      if (i > 0)
        marked[i - 1] = true;
      if (i < n - 1)
        marked[i + 1] = true;
    }
    return ans;
  }
};