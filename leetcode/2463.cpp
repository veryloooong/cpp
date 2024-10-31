#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

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
public:
  long long minimumTotalDistance(vector<int> &robot,
                                 vector<vector<int>> &factory) {
    size_t n = robot.size();
    size_t m = factory.size();

    sort(robot.begin(), robot.end());

    sort(
        factory.begin(), factory.end(),
        [](const vector<int> &x, const vector<int> &y) { return x[0] < y[0]; });

    vector<int> factory_unpacked{};
    for (const auto &arr : factory) {
      int pos = arr[0];
      int cnt = arr[1];
      factory_unpacked.insert(factory_unpacked.end(), cnt, pos);
    }

    // dp[i][j]: cost to repair first i robots with first j factories
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INT_MAX));

    // todo idk what to do wtf

    // repair n robots with m factories
    return dp[n][m];
  }
};

int main() {
  vector<int> robot{0, 4, 6};
  vector<vector<int>> factory{{6, 2}, {2, 2}};

  cout << Solution().minimumTotalDistance(robot, factory);
}