#include <algorithm>
#include <cstdint>
#include <iterator>
#include <limits>
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
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
    sort(items.begin(), items.end());
    vector<int> ans{};

    vector<int> prefix(items.size(), 0);

    for (int i = 0, n = items.size(); i < n; i++) {
      prefix[i] = items[i][1];
      if (i > 0) {
        prefix[i] = max(prefix[i], prefix[i - 1]);
      }
    }

    for (int q : queries) {
      auto it = upper_bound(items.begin(), items.end(),
                            vector<int>{q, numeric_limits<int>::max()});
      if (it == items.begin()) {
        ans.push_back(0);
        continue;
      }

      int idx = distance(items.begin(), it) - 1;
      ans.push_back(prefix[idx]);
    }

    return ans;
  }
};