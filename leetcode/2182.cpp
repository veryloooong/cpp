#include <cstdint>
#include <functional>
#include <map>
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
  std::string repeatLimitedString(std::string s, int repeatLimit) {
    std::map<char, int, std::greater<char>> freq;
    for (const char c : s) {
      freq[c]++;
    }
    std::string ans{};

    return ans;
  }
};