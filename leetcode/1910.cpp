#include <algorithm>
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

  bool check(std::stack<char> stk, std::string &part) {
    for (int i = part.length() - 1; i >= 0; i--) {
      if (stk.top() != part[i])
        return false;
      stk.pop();
    }
    return true;
  }

public:
  std::string removeOccurrences(std::string s, std::string part) {
    std::stack<char> stk;

    for (int i = 0, n = s.length(), m = part.length(); i < n; i++) {
      stk.push(s[i]);
      if ((int)stk.size() >= m && check(stk, part)) {
        for (int j = 0; j < m; j++)
          stk.pop();
      }
    }

    std::string ans;
    while (!stk.empty()) {
      ans += stk.top();
      stk.pop();
    }

    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};