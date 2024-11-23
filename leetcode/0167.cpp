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
  vector<int> twoSum(vector<int> &numbers, int target) {
    for (int lhs = 0, rhs = numbers.size() - 1; lhs < rhs;) {
      int res = numbers[lhs] + numbers[rhs];
      if (res == target)
        return {lhs + 1, rhs + 1};
      else if (res < target)
        lhs++;
      else
        rhs--;
    }

    return {};
  }
};