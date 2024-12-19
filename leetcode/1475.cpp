#include <cstdint>
#include <stack>
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
  std::vector<int> finalPrices(std::vector<int> &prices) {
    std::vector<int> ans{prices};
    std::stack<size_t> stk{};

    for (size_t i = 0, n = prices.size(); i < n; i++) {
      while (!stk.empty() && prices[i] <= prices[stk.top()]) {
        ans[stk.top()] -= prices[i];
        stk.pop();
      }
      stk.push(i);
    }

    return ans;
  }
};