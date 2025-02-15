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

  bool isPunishment(int total, int acc, int cur, std::string const &s, int i) {
    const int n = s.length();
    if (i == n)
      return total == acc + cur;
    const int digit = s[i] - '0';
    return isPunishment(total, acc + cur, digit, s, i + 1) ||
           isPunishment(total, acc, cur * 10 + digit, s, i + 1);
  }

  bool isPunishment(int total) {
    return isPunishment(total, 0, 0, std::to_string(total * total), 0);
  }

public:
  int punishmentNumber(int n) {
    int ans = 0;

    for (int i = 1; i <= n; i++) {
      if (isPunishment(i))
        ans += i * i;
    }

    return ans;
  }
};