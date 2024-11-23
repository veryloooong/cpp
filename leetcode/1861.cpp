#include <cstdint>
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

public:
  vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
    const int m = box.size();
    const int n = box[0].size();

    vector<vector<char>> rotated(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        rotated[i][j] = box[m - 1 - j][i];
      }
    }

    // find rotation for each col
    for (int col = 0; col < m; col++) {
      for (int bottom = n - 1, up = bottom; up >= 0; up--) {
        if (rotated[up][col] == '*') {
          bottom = up - 1;
        } else if (rotated[up][col] == '#') {
          std::swap(rotated[up][col], rotated[bottom][col]);
          bottom--;
        }
      }
    }

    return rotated;
  }
};