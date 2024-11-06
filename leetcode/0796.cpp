#include <algorithm>
#include <cstdint>
#include <string>

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

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
public:
  bool rotateString(string s, string goal) {
    size_t n = s.size();
    if (n != goal.size()) {
      return false;
    }

    if (n == 0) {
      return true;
    }

    for (size_t i = 0; i < n; i++) {
      std::rotate(s.begin(), s.begin() + 1, s.end());
      if (s == goal) {
        return true;
      }
    }

    return false;
  }
};