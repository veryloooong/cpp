#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

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
  vector<int> sortedSquares(vector<int> &nums) {
    vector<int> ans(nums.size());
    int lhs = 0, rhs = nums.size() - 1, pos = rhs;

    while (lhs <= rhs) {
      int lhs2 = (i64)nums[lhs] * nums[lhs];
      int rhs2 = (i64)nums[rhs] * nums[rhs];

      if (lhs2 > rhs2) {
        ans[pos] = lhs2;
        lhs++;
      } else {
        ans[pos] = rhs2;
        rhs--;
      }

      pos--;
    }

    return ans;
  }
};