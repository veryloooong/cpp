#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                                int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> ans{};

    for (int combination = 1; combination < (1 << candidates.size());
         combination++) {
      std::vector<int> subset{};
      for (int i = 0; i < candidates.size(); i++) {
        if (((1 << i) & combination) != 0) {
          subset.push_back(candidates[i]);
        }
      }
      if (std::accumulate(subset.begin(), subset.end(), 0) == target)
        ans.push_back(subset);
    }

    return ans;
  }
};