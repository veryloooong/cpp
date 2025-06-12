#include <algorithm>
#include <cstdint>
#include <cstdlib>
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
  int maxAdjacentDistance(vector<int> &nums) {
    const int n = nums.size();
    nums.push_back(nums.front());

    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, abs(nums[i] - nums[i + 1]));
    }
    return ans;
  }
};
