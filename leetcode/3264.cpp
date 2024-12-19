#include <cstdint>
#include <queue>
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

public:
  std::vector<int> getFinalState(std::vector<int> &nums, int k,
                                 int multiplier) {
    using couple_t = std::pair<int, int>;
    auto cmp = [](const couple_t &a, const couple_t &b) {
      return a.first == b.first ? a.second > b.second : a.first > b.first;
    };

    std::priority_queue<couple_t, std::vector<couple_t>, decltype(cmp)> pq;

    const int n = nums.size();
    for (int i = 0; i < n; i++) {
      pq.push({nums[i], i});
    }

    for (int _ = 0; _ < k; _++) {
      const auto [__, i] = pq.top();
      pq.pop();
      nums[i] *= multiplier;
      pq.push({nums[i], i});
    }

    return nums;
  }
};