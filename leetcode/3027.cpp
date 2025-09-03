#include <algorithm>
#include <cstdint>
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
  int numberOfPairs(vector<vector<int>> &points) {
    int ans = 0;

    ranges::sort(points, ranges::less{}, [](const vector<int> &v) {
      return pair<int, int>{v[0], -v[1]};
    });

    for (int n = points.size(), a = 0; a < n; a++) {
      int y = INT32_MIN;
      for (int b = a + 1; b < n; b++) {
        if (points[a][1] >= points[b][1] && points[b][1] > y) {
          ans++;
          y = points[b][1];
        }
      }
    }

    return ans;
  }
};