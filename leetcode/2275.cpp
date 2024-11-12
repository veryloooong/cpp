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
  int largestCombination(vector<int> &candidates) {
    // log2(10^7) = 24, check for 24 bits
    long long maxBits = 0;

    for (int i = 0; i < 24; i++) {
      maxBits = std::max(
          maxBits, std::count_if(candidates.begin(), candidates.end(),
                                 [&i](int x) { return (x & (1 << i)) != 0; }));
    }

    return maxBits;
  }
};