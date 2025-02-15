#include <algorithm>
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
  int trap(std::vector<int> &height) {
    const int n = height.size();
    std::vector<int> lhs(n, height.front()), rhs(n, height.back());
    int ans = 0;

    // left
    for (int i = 1; i < n; i++)
      lhs[i] = std::max(height[i], lhs[i - 1]);

    for (int i = n - 2; i >= 0; i--)
      rhs[i] = std::max(height[i], rhs[i + 1]);

    for (int i = 0; i < n; i++)
      ans += std::min(lhs[i], rhs[i]) - height[i];

    return ans;
  }
};