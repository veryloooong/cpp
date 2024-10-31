#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iterator>
#include <limits>
#include <set>
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
  int longestSquareStreak(vector<int> &nums) {
    set<int, greater<int>> numsSet(nums.begin(), nums.end());
    vector<int> maxStreak(nums.size(), 1);

    int ans = 1;

    for (auto it = numsSet.begin(); it != numsSet.end(); it++) {
      if (*it >= sqrt(numeric_limits<int>::max()))
        continue;

      if (auto previt = numsSet.find(*it * *it); previt != numsSet.end()) {
        const size_t previdx = distance(numsSet.begin(), previt);
        const size_t idx = distance(numsSet.begin(), it);

        maxStreak[idx] = maxStreak[previdx] + 1;
        ans = max(ans, maxStreak[idx]);
      }
    }

    return ans > 1 ? ans : -1;
  }
};