#include <algorithm>
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
  vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
    int n = nums.size();
    vector<int> prefixXorSums(n, nums[0]);
    for (int i = 1; i < n; i++) {
      prefixXorSums[i] = prefixXorSums[i - 1] ^ nums[i];
    }

    int mask = (1 << maximumBit) - 1;
    for (int i = 0, current = 0; i < n; i++) {
      current ^= nums[i];
      prefixXorSums[n - 1 - i] = current ^ mask;
    }

    // std::reverse(prefixXorSums.begin(), prefixXorSums.end());
    return prefixXorSums;
  }
};