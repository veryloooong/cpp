#include <vector>

class Solution {
public:
  int minSubarray(std::vector<int> &nums, int p) {
    std::vector<int> prefixSums(nums.size(), nums[0]);
    for (size_t i = 1; i < nums.size(); i++) {
      prefixSums[i] = prefixSums[i - 1] + nums[i];
    }

    // TODO
  }
};