#include <algorithm>
#include <cstdint>
#include <numeric>
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
  i64 gridGame(std::vector<std::vector<int>> &grid) {
    const int n = grid[0].size();
    i64 ans = INT64_MAX;
    i64 sumTop = std::accumulate(grid[0].begin(), grid[0].end(), 0LL);
    i64 sumBot = 0;

    for (int i = 0; i < n; i++) {
      sumTop -= grid[0][i];
      ans = std::min(ans, std::max(sumTop, sumBot));
      sumBot += grid[1][i];
    }

    return ans;
  }
};