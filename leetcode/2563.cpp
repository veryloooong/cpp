#include <algorithm>
#include <cstdint>
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
  long long countFairPairs(vector<int> &nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    i64 ans = 0;

    int lhs = 0, rhs = nums.size() - 1;
    while (lhs < rhs) {
      while (nums[lhs] + nums[rhs] > upper && lhs < rhs) {
        rhs--;
      }

      ans += rhs - lhs;
      lhs++;
    }

    lhs = 0, rhs = nums.size() - 1;
    while (lhs < rhs) {
      while (nums[lhs] + nums[rhs] >= lower && lhs < rhs) {
        rhs--;
      }

      ans -= rhs - lhs;
      lhs++;
    }

    return ans;
  }
};