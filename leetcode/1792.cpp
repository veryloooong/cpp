#include <cstdint>
#include <numeric>
#include <queue>
#include <string>
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
  double maxAverageRatio(std::vector<std::vector<int>> &classes,
                         int extraStudents) {
    using pq_val_t = std::pair<double, int>;
    auto cmp = [](const pq_val_t &a, const pq_val_t &b) {
      return a.first < b.first;
    };
    std::priority_queue<pq_val_t, std::vector<pq_val_t>, decltype(cmp)> pq{};

    for (int i = 0, n = classes.size(); i < n; i++) {
      const double p = classes[i][0];
      const double q = classes[i][1];
      const double diff = (p + 1) / (q + 1) - p / q;
      pq.push({diff, i});
    }

    while (extraStudents > 0) {
      const auto [_, i] = pq.top();
      pq.pop();

      classes[i][0]++;
      classes[i][1]++;
      const double p = classes[i][0];
      const double q = classes[i][1];
      const double diff = (p + 1) / (q + 1) - p / q;
      pq.push({diff, i});

      extraStudents--;
    }

    return std::accumulate(classes.begin(), classes.end(), 0.0,
                           [](const double &a, const std::vector<int> &b) {
                             return a + static_cast<double>(b[0]) / b[1];
                           }) /
           classes.size();
  }
};