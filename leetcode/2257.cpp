#include <algorithm>
#include <array>
#include <cstdint>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

using namespace std;

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

  const array<pair<int, int>, 4> dirs{
      make_pair(1, 0),
      make_pair(0, 1),
      make_pair(-1, 0),
      make_pair(0, -1),
  };

public:
  int countUnguarded(int m, int n, vector<vector<int>> &guards,
                     vector<vector<int>> &walls) {
    vector<vector<char>> grid(m, vector<char>(n, 1));

    for (const auto &w : walls) {
      grid[w[0]][w[1]] = 'w';
    }

    for (const auto &g : guards) {
      grid[g[0]][g[1]] = 'g';
    }

    for (const auto &g : guards) {
      const int x = g[0];
      const int y = g[1];
      for (const auto [dx, dy] : dirs) {
        int cx = x + dx, cy = y + dy;
        while (cx >= 0 && cx < m && cy >= 0 && cy < n && grid[cx][cy] != 'g' &&
               grid[cx][cy] != 'w') {
          grid[cx][cy] = 0;
          cx += dx;
          cy += dy;
        }
      }
    }

    return std::accumulate(grid.begin(), grid.end(), 0,
                           [](int acc, const vector<char> &row) {
                             return acc + std::count(row.begin(), row.end(), 1);
                           });
  }
};