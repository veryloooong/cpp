#include <algorithm>
#include <cstdint>
#include <numeric>
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
  double findMaxAverage(std::vector<int> &nums, int k) {
    double acc = std::accumulate(nums.begin(), nums.begin() + k, 0.0);
    double best = acc;
    for (size_t i = k; i < nums.size(); i++) {
      acc = acc + nums[i] - nums[i - k];
      best = std::max(best, acc);
    }

    return best / k;
  }
};