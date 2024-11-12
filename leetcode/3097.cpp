#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cstdint>
#include <vector>

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

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
public:
  int minimumSubarrayLength(vector<int> &nums, int k) {
    int n = nums.size();
    size_t val = k;

    bitset<32> bitmask{};
    array<int, 32> bitmask_freq{};

    auto bitmask_set_func = [&bitmask, &bitmask_freq](int x) {
      for (int i = 0; i < 32; i++)
        if (x & (1 << i) && ++bitmask_freq[i] == 1)
          bitmask.set(i);
    };

    auto bitmask_rmv_func = [&bitmask, &bitmask_freq](int x) {
      for (int i = 0; i < 32; i++)
        if (x & (1 << i) && --bitmask_freq[i] == 0)
          bitmask.reset(i);
    };

    vector<int> minSubarrays(n, n);
    int ans = INT_MAX;

    for (int lhs = 0, rhs = 0; rhs < n; rhs++) {
      bitmask_set_func(nums[rhs]);
      while (bitmask.to_ullong() >= val && lhs <= rhs) {
        ans = min(ans, rhs - lhs + 1);
        bitmask_rmv_func(nums[lhs++]);
      }
    }

    return (ans == INT_MAX ? -1 : ans);
  }
};