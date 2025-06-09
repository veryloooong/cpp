#include <algorithm>
#include <cstdint>

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

  i64 steps(i64 n, i64 a, i64 b) {
    i64 ans = 0;
    while (a <= n) {
      ans += min(n + 1, b) - a;
      a *= 10;
      b *= 10;
    }
    return ans;
  }

public:
  int findKthNumber(int n, int k) {
    int curr = 1;
    k--;

    while (k > 0) {
      i64 step = steps(n, curr, curr + 1);
      if (step <= k) {
        curr++;
        k -= step;
      } else {
        curr *= 10;
        k--;
      }
    }
      
    return curr;
  }
};
