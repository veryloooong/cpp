#include <cctype>
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
  std::string clearDigits(std::string s) {
    const int n = s.size();
    std::vector<bool> check(n);

    for (int i = 0; i < n; i++) {
      if (std::isdigit(s[i])) {
        check[i] = true;
        for (int j = i - 1; j >= 0; j--) {
          if (!std::isdigit(s[j]) && !check[j]) {
            check[j] = true;
            break;
          }
        }
      }
    }

    std::string ans;
    for (int i = 0; i < n; i++) {
      if (!check[i])
        ans += s[i];
    }

    return ans;
  }
};