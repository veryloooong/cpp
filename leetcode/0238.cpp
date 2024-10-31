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
  vector<int> productExceptSelf(vector<int> &nums) {
    const int n = nums.size();

    vector<int> ans(n);

    int lhs = 1, rhs = 1;
    for (int i = 0; i < n; i++) {
      ans[i] = lhs;
      lhs *= nums[i];
    }

    for (int i = n - 1; i >= 0; i--) {
      ans[i] *= rhs;
      rhs *= nums[i];
    }

    return ans;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4};
  vector<int> res = Solution().productExceptSelf(nums);
}