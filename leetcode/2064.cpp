#include <cstdint>
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

  bool canBeDistributedPerStoreLessThan(int n, vector<int> &quantities, int k) {
    i32 stores = 0;
    for (int q : quantities) {
      stores += (q + k - 1) / k;
    }
    return stores <= n;
  }

public:
  int minimizedMaximum(int n, vector<int> &quantities) {
    int l = 1, r = 1e9;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (canBeDistributedPerStoreLessThan(n, quantities, m)) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};