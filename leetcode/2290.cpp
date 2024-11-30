#include <algorithm>
#include <array>
#include <cstdint>
#include <functional>
#include <queue>
#include <set>
#include <string>
#include <utility>
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

  const std::array<std::pair<int, int>, 4> dirs{
      std::make_pair(1, 0), std::make_pair(0, 1), std::make_pair(-1, 0),
      std::make_pair(0, -1)};

public:
  int minimumObstacles(std::vector<std::vector<int>> &grid) {
    const int n = grid.size();
    const int m = grid.front().size();

    std::priority_queue<std::tuple<int, int, int>,
                        std::vector<std::tuple<int, int, int>>, std::greater<>>
        pq;

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m));

    pq.push({0, 0, 0});
    while (!pq.empty()) {
      const auto [c, x, y] = pq.top();
      pq.pop();

      if (x == n - 1 && y == m - 1)
        return c;

      if (visited[x][y])
        continue;
      visited[x][y] = true;

      for (const auto [dx, dy] : dirs) {
        const int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          continue;

        pq.push({c + grid[nx][ny], nx, ny});
      }
    }

    return n + m - 2;
  }
};