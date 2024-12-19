#include <cstdint>
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
  std::vector<bool> isArraySpecial(std::vector<int> &nums,

                                   std::vector<std::vector<int>> &queries) {
    const int n = nums.size();

    std::vector<int> arr(n, 1);
    for (int i = 1, cur = 1; i < n; i++) {
      if (((nums[i] - nums[i - 1]) & 1) == 0)
        cur++;
      arr[i] = cur;
    }

    std::vector<bool> ans(queries.size());
    for (int i = 0, m = queries.size(); i < m; i++) {
      ans[i] = arr[queries[i][0]] == arr[queries[i][1]];
    }

    return ans;
  }
};