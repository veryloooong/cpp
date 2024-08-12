#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class DisjointSet {
private:
  vector<int> parent;
  vector<int> size;

public:
  DisjointSet(int n) : parent(n), size(n, 1) {
    std::iota(parent.begin(), parent.end(), 0);
  }

  int find(int x) { return (x == parent[x] ? x : parent[x] = find(parent[x])); }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u != v) {
      if (size[u] > size[v]) {
        size[u] += size[v];
        parent[v] = u;
      } else {
        size[v] += size[u];
        parent[u] = v;
      }

      return true;
    } else
      return false;
  }
};

class Solution {
private:
  DisjointSet dsu{0};
  int regions;

  int coordsToIdx(int n, int x, int y) { return n * x + y; }

  void findRegion(int u, int v) {
    if (!dsu.unite(u, v))
      regions++;
  }

public:
  Solution() {}

  int regionsBySlashes(vector<string> &grid) {
    int n = grid.size() + 1;
    int gridSize = n * n;

    dsu = DisjointSet(gridSize);
    regions = 0;

    for (int i = 1; i < n; i++) {
      findRegion(coordsToIdx(n, 0, i), coordsToIdx(n, 0, i - 1));
      findRegion(coordsToIdx(n, i - 1, n - 1), coordsToIdx(n, i, n - 1));
      findRegion(coordsToIdx(n, n - 1, n - i),
                 coordsToIdx(n, n - 1, n - i - 1));
      findRegion(coordsToIdx(n, n - 1 - i, 0), coordsToIdx(n, n - i, 0));
    }

    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - 1; j++) {
        if (grid[i][j] == '/') {
          int v1 = coordsToIdx(n, i, j + 1);
          int v2 = coordsToIdx(n, i + 1, j);
          findRegion(v1, v2);
        } else if (grid[i][j] == '\\') {
          int v1 = coordsToIdx(n, i, j);
          int v2 = coordsToIdx(n, i + 1, j + 1);
          findRegion(v1, v2);
        }
      }
    }

    return regions;
  }
};

int main() {
  Solution s = Solution();
  vector<string> grid = {" /", "/ "};
  cout << s.regionsBySlashes(grid) << endl;
}