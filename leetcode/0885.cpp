#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                      int cStart) {
    vector<pair<int, int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> ans{};

    ans.push_back({rStart, cStart});

    int rCurrent = rStart;
    int cCurrent = cStart;
    for (int turn = 0; ans.size() < rows * cols; turn++) {
      auto dir = direction[turn % 4];

      for (int step = 0; step < turn / 2 + 1; step++) {
        rCurrent += dir.first;
        cCurrent += dir.second;
        if (0 <= rCurrent && rCurrent < rows && 0 <= cCurrent &&
            cCurrent < cols)
          ans.push_back({rCurrent, cCurrent});
      }
    }

    return ans;
  }
};