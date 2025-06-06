#include <cstdint>
#include <string>
#include <unordered_map>
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
  long long countBadPairs(std::vector<int> &nums) {
    const int n = nums.size();
    i64 ans = 0;

    std::unordered_map<int, int> counts;
    for (int i = 0; i < n; i++) {
      ans += i - counts[nums[i] - i]++;
    }

    return ans;
  }
};