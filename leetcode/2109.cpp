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
  std::string addSpaces(std::string s, std::vector<int> &spaces) {
    std::string ans{};

    const int n = spaces.size();

    ans += s.substr(0, spaces[0]);

    for (int i = 1; i < n; i++) {
      ans += " " + s.substr(spaces[i - 1], spaces[i] - spaces[i - 1]);
    }

    ans += " " + s.substr(spaces.back());

    return ans;
  }
};