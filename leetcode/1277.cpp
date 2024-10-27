#include <algorithm>
#include <cstdint>
#include <vector>

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
  int countSquares(vector<vector<int>> &matrix) {
    const size_t n = matrix.size();
    const size_t m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    int ans = 0;

    for (size_t i = 0; i < n; i++) {
      dp[i][0] = matrix[i][0];
      ans += dp[i][0];
    }

    for (size_t j = 1; j < m; j++) {
      dp[0][j] = matrix[0][j];
      ans += dp[0][j];
    }

    for (size_t i = 1; i < n; i++) {
      for (size_t j = 1; j < m; j++) {
        if (matrix[i][j])
          dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
        ans += dp[i][j];
      }
    }

    return ans;
  }
};