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
  int maxScore(std::string s) {
    int n = s.size();
    std::vector<int> suffix(s.size());
    suffix.back() = (s.back() == '1');
    for (int i = n - 2; i >= 0; i--) {
      suffix[i] = suffix[i + 1] + (s[i] == '1');
    }
    int zeros = 0, ans = 0;
    for (int i = 0; i < n - 1; i++) {
      zeros += (s[i] == '0');
      ans = std::max(ans, zeros + suffix[i + 1]);
    }

    return ans;
  }
};