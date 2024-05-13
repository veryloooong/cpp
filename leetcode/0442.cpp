#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> findDuplicates(vector<int> &nums) {
    vector<int> ans;
    for (size_t i = 0, n = nums.size(); i < n; i++) {
      int idx = abs(nums[i]) - 1;
      if (nums[idx] < 0) {
        ans.push_back(abs(nums[i]));
      } else {
        nums[idx] *= -1;
      }
    }
    return ans;
  }
};