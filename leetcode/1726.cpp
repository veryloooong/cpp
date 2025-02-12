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
  int tupleSameProduct(std::vector<int> &nums) {
    const int n = nums.size();
    std::unordered_map<int, int> counts;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        counts[nums[i] * nums[j]]++;
      }
    }

    int ans = 0;
    for (const auto &[k, v] : counts) {
      ans += 8 * v * (v - 1);
    }

    return ans / 2;
  }
};