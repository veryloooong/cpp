#include <algorithm>
#include <cstdint>
#include <string>
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
  long long distributeCandies(int n, int limit) {
    i64 ans = 0;

    for (int i = 0, I = min(n, limit); i <= I; i++) {
      ans += max(min(limit, n - i) - max(0, n - i - limit) + 1, 0);
    }

    return ans;
  }
};