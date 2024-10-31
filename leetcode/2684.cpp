#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
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
  int maxMoves(vector<vector<int>> &grid) {
    // grid.size() = rows, grid[0].size = cols
    const int n = grid.size();
    const int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m));

    for (int j = m - 2; j >= 0; j--) {
      for (int i = 0; i < n; i++) {
        bool changed = false;

        // row above
        if (i > 0) {
          if (grid[i][j] < grid[i - 1][j + 1]) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + 1);
            changed = true;
          }
        }

        // same row
        if (grid[i][j] < grid[i][j + 1]) {
          dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1);
          changed = true;
        }

        // row below
        if (i < n - 1) {
          if (grid[i][j] < grid[i + 1][j + 1]) {
            dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 1);
            changed = true;
          }
        }

        if (!changed)
          dp[i][j] = 0;
      }
    }

    int ans = numeric_limits<int>::min();
    for (int i = 0; i < n; i++) {
      ans = max(ans, dp[i][0]);
    }

    return ans;
  }
};

int main() {
  vector<vector<int>> grid = {
      {2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};

  cout << Solution().maxMoves(grid) << endl;

  grid = {{3, 2, 4}, {2, 1, 9}, {1, 1, 7}};

  cout << Solution().maxMoves(grid) << endl;
}