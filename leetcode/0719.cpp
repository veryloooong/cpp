#include <algorithm>
#include <vector>

class Solution {
private:
  int countPairsNotGreaterThan(std::vector<int> &nums, int m) {
    const int n = nums.size();
    int ans = 0;
    for (int lhs = 0, rhs = 1; rhs < n; rhs++) {
      while (lhs < rhs && nums[rhs] - nums[lhs] > m)
        lhs++;
      ans += rhs - lhs;
    }
    return ans;
  }

public:
  int smallestDistancePair(std::vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());

    int l = 0, r = nums.back() - nums.front();
    while (l < r) {
      int m = l + (r - l) / 2;
      int pairs = countPairsNotGreaterThan(nums, m);
      if (pairs < k)
        l = m + 1;
      else
        r = m;
    }

    return l;
  }
};