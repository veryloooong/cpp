#include <array>
#include <cstdint>
#include <functional>
#include <queue>
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

  typedef std::tuple<int, int, int> coord_t; // (time, x, y)

public:
  int minimumTime(std::vector<std::vector<int>> &grid) {
    if (grid[0][1] > 1 && grid[1][0] > 1)
      return -1;

    const int n = grid.size();
    const int m = grid.front().size();

    std::priority_queue<coord_t, std::vector<coord_t>, std::greater<>> pq;
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m));

    pq.push({0, 0, 0});
    visited[0][0] = true;

    while (!pq.empty()) {
      const auto [time, x, y] = pq.top();
      pq.pop();
      if (x == n - 1 && y == m - 1)
        return time;

      for (const auto [dx, dy] : dirs) {
        const int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          continue;
        if (visited[nx][ny])
          continue;

        const int time_parity = 1 - (grid[nx][ny] - time) % 2;
        const int next_time = std::max(time + 1, grid[nx][ny] + time_parity);
        pq.push({next_time, nx, ny});
        visited[nx][ny] = true;
      }
    }

    return -1;
  }
};