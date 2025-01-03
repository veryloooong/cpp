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
  int waysToSplitArray(std::vector<int> &nums) {
    i64 total = std::accumulate(nums.begin(), nums.end(), 0LL);
    int ans = 0;
    i64 cur = 0;
    for (size_t i = 0; i < nums.size() - 1; i++) {
      cur += nums[i];
      ans += (cur >= total - cur);
    }

    return ans;
  }
};