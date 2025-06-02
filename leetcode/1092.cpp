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

  std::string sequence(std::string str1, std::string str2) {
    const int n1 = str1.length();
    const int n2 = str2.length();

    std::vector<std::vector<std::string>> dp(n1 + 1,
                                             std::vector<std::string>(n2 + 1));
    for (int i = 1; i <= n1; i++) {
      for (int j = 1; j <= n2; j++) {
        if (str1[i - 1] == str2[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + str1[i - 1];
        else
          dp[i][j] = dp[i - 1][j].length() > dp[i][j - 1].length()
                         ? dp[i - 1][j]
                         : dp[i][j - 1];
      }
    }

    return dp[n1][n2];
  }

public:
  std::string shortestCommonSupersequence(std::string str1, std::string str2) {
    const std::string lcs = sequence(str1, str2);
    int i = 0, j = 0;
    std::string ans;

    for (const char c : lcs) {
      while (str1[i] != c)
        ans += str1[i++];
      while (str2[j] != c)
        ans += str2[j++];
      i++;
      j++;
      ans += c;
    }

    return ans + str1.substr(i) + str2.substr(j);
  }
};