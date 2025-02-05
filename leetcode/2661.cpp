#include <cstdint>
#include <string>
#include <unordered_map>
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

public:
  int firstCompleteIndex(std::vector<int> &arr,
                         std::vector<std::vector<int>> &mat) {
    const int n = mat.size(), m = mat[0].size();
    std::unordered_map<int, std::pair<int, int>> positions{};

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        positions[mat[i][j]] = {i + 1, j + 1};

    std::vector<int> rows(n + 1), cols(m + 1);

    for (int i = 0, sz = arr.size(); i < sz; i++) {
      const auto &[x, y] = positions[arr[i]];
      if (++rows[x] == m)
        return i;
      if (++cols[y] == n)
        return i;
    }

    return 0;
  }
};