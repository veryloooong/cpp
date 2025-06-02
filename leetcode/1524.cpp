#include <cstdint>
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
  int numOfSubarrays(std::vector<int> &arr) {
    constexpr int MOD = 1000000007;
    const int n = arr.size();

    i64 ans = 0;
    std::vector<int> odds(n + 1), evens(n + 1);
    for (int i = 1; i <= n; i++) {
      if (arr[i - 1] & 1) {
        evens[i] = odds[i - 1];
        odds[i] = evens[i - 1] + 1;
      } else {
        evens[i] = evens[i - 1] + 1;
        odds[i] = odds[i - 1];
      }
      ans = (ans + odds[i]) % MOD;
    }

    return ans;
  }
};