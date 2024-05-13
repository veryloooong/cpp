#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    vector<int> ans{};
    size_t i = 0;
    size_t n = nums.size();

    for (i = 0; i < n; ++i) {
      int idx = abs(nums[i]) - 1;
      if (nums[idx] > 0)
        nums[idx] *= -1;
    }

    for (i = 0; i < n; ++i) {
      if (nums[i] > 0)
        ans.push_back(i + 1);
    }

    return ans;
  }
};