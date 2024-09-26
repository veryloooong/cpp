#include <algorithm>
#include <vector>

class Solution {
public:
  int longestSubarray(std::vector<int> &nums) {
    int ans = 0;
    int indexMax = 0;
    int subarraySize = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == nums[indexMax]) {
        ans = std::max(ans, ++subarraySize);
      } else if (nums[i] > nums[indexMax]) {
        indexMax = i;
        ans = 1;
        subarraySize = 1;
      } else {
        subarraySize = 0;
      }
    }

    return ans;
  }
};