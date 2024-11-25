#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <limits>
#include <string>
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

public:
  long long maxMatrixSum(std::vector<std::vector<int>> &matrix) {
    long long total = 0;
    int absmin = std::numeric_limits<int>::max();
    bool odd_negatives = false;

    for (const std::vector<int> &row : matrix) {
      for (const int &x : row) {
        int abs = std::abs(x);
        odd_negatives ^= (abs != x);
        total += abs;
        absmin = std::min(absmin, abs);
      }
    }

    return total - (odd_negatives ? 2 * absmin : 0);
  }
};