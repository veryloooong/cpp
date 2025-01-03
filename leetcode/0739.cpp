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
  std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
    const int n = temperatures.size();
    std::vector<int> ans(n);
    std::stack<int> stack;

    for (int j = 0; j < n; j++) {
      while (!stack.empty() && temperatures[stack.top()] < temperatures[j]) {
        const int i = stack.top();
        stack.pop();
        ans[i] = j - i;
      }

      stack.push(j);
    }

    return ans;
  }
};