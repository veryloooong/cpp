#include <functional>
#include <utility>
#include <vector>

using namespace std;

class Solution {
private:
  vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  int countRegions(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> seen(n, vector<bool>(m, false));
    int regions = 0;

    function<void(int, int)> dfs = [&](int x, int y) {
      seen[x][y] = true;
      for (const auto &[dx, dy] : dirs) {
        int xn = x + dx, yn = y + dy;
        if (0 <= xn && xn < n && 0 <= yn && yn < m && !seen[xn][yn] &&
            grid[xn][yn] == 1)
          dfs(xn, yn);
      }
    };

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (grid[i][j] == 1 && !seen[i][j]) {
          regions++;
          dfs(i, j);
        }

    return regions;
  }

public:
  int minDays(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    if (countRegions(grid) != 1)
      return 0;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (grid[i][j] == 1) {
          grid[i][j] = 0;
          if (countRegions(grid) != 1)
            return 1;
          grid[i][j] = 1;
        }

    return 2;
  }
};