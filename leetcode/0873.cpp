#include <algorithm>
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
  int lenLongestFibSubseq(std::vector<int> &arr) {
    std::unordered_set<int> vals(arr.begin(), arr.end());
    std::unordered_map<int, std::unordered_map<int, int>> dp;
    int ans = 0;

    for (int j = 0, n = arr.size(); j < n; j++) {
      for (int i = 0; i < j; i++) {
        if (arr[j] - arr[i] < arr[i] && vals.contains(arr[j] - arr[i])) {
          dp[arr[i]][arr[j]] = (dp[arr[j] - arr[i]].contains(arr[i])
                                    ? dp[arr[j] - arr[i]][arr[i]]
                                    : 2) +
                               1;
          ans = std::max(ans, dp[arr[i]][arr[j]]);
        }
      }
    }

    return ans;
  }
};
