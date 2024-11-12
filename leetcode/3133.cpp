#include <cmath>
#include <cstdint>

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
  long long minEnd(int n, int x) {
    if (n == 1)
      return x;

    long long ans = x;
    long long cnt = n - 1;
    int i = 0;

    while (cnt > 0) {
      if (((long long)x >> i & 1) == 0) {
        ans = ans | (cnt & 1) << i;
        cnt >>= 1;
      }
      i++;
    }

    return ans;
  }
};