#include <cstdint>
#include <string>

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
  bool canMakeSubsequence(std::string str1, std::string str2) {
    int i = 0, j = 0;
    int n1 = str1.size(), n2 = str2.size();

    for (; i < n1; i++) {
      if ((str1[i] == str2[j]) || (((str1[i] - 'a' + 1) % 26 + 'a') == str2[j]))
        j++;
    }

    return j == n2;
  }
};