#include <bitset>
#include <vector>

using namespace std;

class Solution {
private:
  int rows;
  int cols;

  bool isMagicSquareSubgrid(vector<vector<int>> &grid, int xLeft, int yLeft) {
    if (grid[xLeft + 1][yLeft + 1] != 5)
      return false;

    if (grid[xLeft][yLeft] % 2 != 0)
      return false;

    bitset<9> check{};

    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        try {
          if (check.test(grid[xLeft + i][yLeft + j] - 1))
            return false;
          else
            check.set(grid[xLeft + i][yLeft + j] - 1);
        } catch (exception) {
          return false;
        }
      }

    for (int i = 0; i < 3; i++) {
      int rowSum = grid[xLeft + i][yLeft + 0] + grid[xLeft + i][yLeft + 1] +
                   grid[xLeft + i][yLeft + 2];
      int colSum = grid[xLeft + 0][yLeft + i] + grid[xLeft + 1][yLeft + i] +
                   grid[xLeft + 2][yLeft + i];
      if (rowSum != 15 || colSum != 15)
        return false;
    }

    int diagonalSum1 = grid[xLeft + 0][yLeft + 0] + grid[xLeft + 1][yLeft + 1] +
                       grid[xLeft + 2][yLeft + 2];
    int diagonalSum2 = grid[xLeft + 0][yLeft + 2] + grid[xLeft + 1][yLeft + 1] +
                       grid[xLeft + 2][yLeft + 0];
    if (diagonalSum1 != 15 || diagonalSum2 != 15)
      return false;
    return true;
  }

public:
  int numMagicSquaresInside(vector<vector<int>> &grid) {
    int ans = 0;
    rows = grid.size();
    cols = grid[0].size();

    for (int i = 0; i + 2 < rows; i++)
      for (int j = 0; j + 2 < cols; j++)
        ans += isMagicSquareSubgrid(grid, i, j);

    return ans;
  }
};

int main() {
  vector<vector<int>> grid = {
      {4, 10, 1, 6}, {2, 5, 8, 5}, {9, 0, 6, 4}, {1, 7, 2, 9}};
}