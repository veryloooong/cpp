#include <array>
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
  bool areAlmostEqual(std::string s1, std::string s2) {
    const int n = s1.length();
    std::array<int, 2> indexes{};
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i]) {
        if (j == 2)
          return false;
        else
          indexes[j++] = i;
      }
    }

    return j != 1 && s1[indexes[0]] == s2[indexes[1]] &&
           s1[indexes[1]] == s2[indexes[0]];
  }
};