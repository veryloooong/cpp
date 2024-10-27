#include <algorithm>
#include <cstdint>
#include <stdexcept>
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
  string mergeAlternately(string word1, string word2) {
    string ans{};

    for (size_t i = 0, n = max(word1.size(), word2.size()), n1 = word1.size(),
                n2 = word2.size();
         i < n; i++) {
      if (i < n1)
        ans.push_back(word1[i]);
      if (i < n2)
        ans.push_back(word2[i]);
    }

    return ans;
  }
};