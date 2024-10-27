#include <algorithm>
#include <cstdint>
#include <limits>
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
  int maxProfit(vector<int> &prices) {
    int ans = 0;
    int minPrice = numeric_limits<int>::max();

    for (const int &price : prices) {
      minPrice = min(minPrice, price);
      ans = max(ans, price - minPrice);
    }

    return ans;
  }
};