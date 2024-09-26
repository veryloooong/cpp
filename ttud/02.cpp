#include <iostream>
#include <vector>
using namespace std;

int main() {
  int r, c;
  cin >> r >> c;

  vector<vector<int>> grid(r, vector<int>(c));

  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      cin >> grid[i][j];

  for (int i = 0; i < r; i++)
    for (int j = 1; j < c; j++)
      grid[i][j] += grid[i][j - 1];

  for (int j = 0; j < c; j++)
    for (int i = 1; i < r; i++)
      grid[i][j] += grid[i - 1][j];

  int q;
  cin >> q;
  for (int qi = 0; qi < q; qi++) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;
    c1--;
    r2--;
    c2--;
    cout << grid[r2][c2] - (r1 > 0 ? grid[r1 - 1][c2] : 0) -
                (c1 > 0 ? grid[r2][c1 - 1] : 0) +
                (r1 * c1 > 0 ? grid[r1 - 1][c1 - 1] : 0)
         << endl;
  }
}