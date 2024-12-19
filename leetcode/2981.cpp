#include <algorithm>
#include <cstdint>
#include <string>
#include <unordered_map>
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

  bool isSpecial(const std::string &s) {
    const char &ck = s.front();
    return std::all_of(s.cbegin(), s.cend(),
                       [&ck](const char &c) { return c == ck; });
  }

public:
  int maximumLength(std::string s) {
    int ans = -1;

    std::unordered_map<std::string, int> seen{};
    for (int len = 1, n = s.size(), n3 = n - 2; len <= n3; len++) {
      seen.clear();
      for (int i = 0, r = n - len + 1; i < r; i++) {
        const std::string subs = s.substr(i, len);
        if (isSpecial(subs))
          if (++seen[subs] == 3) {
            ans = len;
            break;
          }
      }
    }

    return ans;
  }
};