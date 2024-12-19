#include <algorithm>
#include <cstdint>
#include <map>
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
  long long continuousSubarrays(std::vector<int> &nums) {
    i64 ans = 0;
    const int n = nums.size();
    std::map<int, int> freq{};

    for (int lhs = 0, rhs = 0; rhs < n; rhs++) {
      freq[nums[rhs]]++;
      while (freq.rbegin()->first - freq.begin()->first > 2) {
        if (--freq[nums[lhs]] == 0) {
          freq.erase(nums[lhs]);
        }
        lhs++;
      }
      ans += rhs - lhs + 1;
    }

    return ans;
  }
};