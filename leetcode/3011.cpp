#include <algorithm>
#include <bit>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>

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
  bool canSortArray(std::vector<int> &nums) {
    std::vector<int> setBitIndex{0};

    for (int i = 1, n = nums.size(); i < n; i++) {
      if (std::popcount(static_cast<std::uint32_t>(nums[i])) !=
          std::popcount(static_cast<std::uint32_t>(nums[setBitIndex.back()]))) {
        setBitIndex.push_back(i);
      }
    }

    setBitIndex.push_back(nums.size());

    for (int i = 1, n = setBitIndex.size() - 1; i < n; i++) {
      if (*std::max_element(std::next(nums.begin(), setBitIndex[i - 1]),
                            std::next(nums.begin(), setBitIndex[i])) >
          *std::min_element(std::next(nums.begin(), setBitIndex[i]),
                            std::next(nums.begin(), setBitIndex[i + 1])))
        return false;
    }

    return true;
  }
};

int main() {
  std::vector<int> nums = {8, 4, 2, 30, 15};
  std::cout << std::boolalpha << Solution().canSortArray(nums) << std::endl;
}