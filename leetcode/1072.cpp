#include <cstdint>
#include <iostream>
#include <unordered_set>
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
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    const int rows = matrix.size();
    const int cols = matrix[0].size();
    int ans = 0;
    vector<int> flip(cols);

    unordered_set<int> seenIndexes{};

    for (int i = 0; i < rows; i++) {
      if (seenIndexes.contains(i))
        continue;
      int cnt = 0;
      for (int j = 0; j < cols; j++)
        flip[j] = 1 ^ matrix[i][j];
      for (int j = 0; j < rows; j++)
        if (matrix[i] == matrix[j] || matrix[j] == flip) {
          cnt++;
          seenIndexes.insert(j);
        }

      ans = max(ans, cnt);
    }

    return ans;
  }
};

int main() {
  vector<vector<int>> matrix{{0, 1}, {1, 0}};
  cout << Solution().maxEqualRowsAfterFlips(matrix) << endl;
}