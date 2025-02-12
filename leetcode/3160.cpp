#include <cstdint>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
  std::vector<int> queryResults(int limit,
                                std::vector<std::vector<int>> &queries) {
    std::unordered_map<int, std::unordered_set<int>> colorCount;
    std::vector<int> colorBalls(limit + 1);
    std::vector<int> ans(queries.size());

    for (int i = 0, n = queries.size(); i < n; i++) {
      const auto q = queries[i];
      const int k = q[0], v = q[1];
      if (colorBalls[k] != 0) {
        int ov = colorBalls[k];
        colorCount[ov].erase(k);
        if (colorCount[ov].empty())
          colorCount.erase(ov);
      }
      colorBalls[k] = v;
      colorCount[v].insert(k);
      ans[i] = colorCount.size();
    }

    return ans;
  }
};