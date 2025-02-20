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

  bool backtrack(std::vector<int> &arr, int n, int i, int bitmask) {
    const int sz = arr.size();
    if (i == sz)
      return true;
    if (arr[i] > 0)
      return backtrack(arr, n, i + 1, bitmask);

    for (int num = n; num >= 1; num--) {
      if (bitmask & (1 << num))
        continue;

      if (num == 1) {
        arr[i] = num;
        if (backtrack(arr, n, i + 1, bitmask | (1 << num)))
          return true;
        arr[i] = 0;
      } else {
        if (i + num >= sz || arr[i + num] > 0)
          continue;
        arr[i] = num;
        arr[i + num] = num;
        if (backtrack(arr, n, i + 1, bitmask | (1 << num)))
          return true;
        arr[i] = 0;
        arr[i + num] = 0;
      }
    }

    return false;
  }

public:
  std::vector<int> constructDistancedSequence(int n) {
    std::vector<int> ans(2 * n - 1);

    backtrack(ans, n, 0, 0);

    return ans;
  }
};