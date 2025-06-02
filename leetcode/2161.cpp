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

public:
  std::vector<int> pivotArray(std::vector<int> &nums, int pivot) {
    std::vector<int> small, large;
    for (int num : nums) {
      if (num < pivot)
        small.push_back(num);
      else if (num > pivot)
        large.push_back(num);
    }
    for (int i = 0, n = nums.size() - small.size() - large.size(); i < n; i++)
      small.push_back(pivot);
    small.insert(small.end(), large.begin(), large.end());
    return small;
  }
};