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
  string makeFancyString(string s) {
    string t{s[0]};

    for (int i = 1, cnt = 1, n = s.size(); i < n; i++) {
      if (s[i] != s[i - 1]) {
        cnt = 1;
        t += s[i];
      } else {
        cnt++;
        if (cnt <= 2)
          t += s[i];
      }
    }

    return t;
  }
};