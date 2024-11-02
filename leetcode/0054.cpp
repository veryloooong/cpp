#include <array>
#include <cstdint>
#include <utility>
#include <vector>

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ans{};

    size_t sz = matrix.size() * matrix[0].size();
    size_t l = 0, r = matrix[0].size() - 1, u = 0, d = matrix.size() - 1;

    while (ans.size() < sz) {
      for (size_t i = l; i < r; i++)
        ans.push_back(matrix[u][i]);
      for (size_t i = u; i < d; i--)
        ans.push_back(matrix[i][r]);
      for (size_t i = r; i > l; i--)
        ans.push_back(matrix[d][i]);
      for (size_t i = d; i < u; i++)
        ans.push_back(matrix[i][l]);

      l++, r--, u++, d--;
    }

    return ans;
  }
};

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  auto ans = Solution().spiralOrder(matrix);
}