#include <algorithm>
#include <cstdint>
#include <iterator>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
  int countPalindromicSubsequence(std::string s) {
    int n = s.length();
    int ans = 0;

    std::vector<int> first_occurrence(26, n), last_occurrence(26, 0);
    for (int i = 0; i < n; i++) {
      const int index = s[i] - 'a';
      first_occurrence[index] = std::min(first_occurrence[index], i);
      last_occurrence[index] = i;
    }

    for (int i = 0; i < 26; i++) {
      if (last_occurrence[i] - first_occurrence[i] >= 2) {
        ans += std::unordered_set<int>(
                   std::next(s.begin(), first_occurrence[i] + 1),
                   std::next(s.begin(), last_occurrence[i]))
                   .size();
      }
    }

    return ans;
  }
};