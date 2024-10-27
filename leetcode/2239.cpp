#include <algorithm>
#include <cstdint>
#include <cstdlib>
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
  int findClosestNumber(vector<int> &nums) {
    return *min_element(nums.begin(), nums.end(), [](int x, int y) {
      if (abs(x) == abs(y))
        return x > 0;
      else
        return abs(x) < abs(y);
    });
  }
};