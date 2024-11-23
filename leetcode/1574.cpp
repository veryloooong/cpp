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

public:
  int findLengthOfShortestSubarray(vector<int> &arr) {
    int n = arr.size();
    int lhs = 0, rhs = n - 1;

    while (lhs < n - 1 && arr[lhs] <= arr[lhs + 1]) {
      lhs++;
    }

    if (lhs == n - 1) {
      return 0;
    }

    while (rhs > 0 && arr[rhs] >= arr[rhs - 1]) {
      rhs--;
    }

    int ans = min(n - lhs - 1, rhs);

    int i = lhs, j = n - 1;
    while (i >= 0 && j >= rhs && i <= j) {
      if (arr[i] <= arr[j])
        j--;
      else
        i--;
      ans = min(ans, j - i);
    }

    return ans;
  }
};