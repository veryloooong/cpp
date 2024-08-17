#include <algorithm>
#include <ranges>
#include <vector>

class Solution {
public:
  int maxDistance(std::vector<std::vector<int>> &arrays) {
    int minNum = arrays[0].front(), maxNum = arrays[0].back();
    int ans = 0;

    for (const auto &arr : std::ranges::drop_view(arrays, 1)) {
      int current = std::max(std::abs(arr.front() - maxNum),
                             std::abs(arr.back() - minNum));
      ans = std::max(ans, current);
      minNum = std::min(minNum, arr.front());
      maxNum = std::max(maxNum, arr.back());
    }

    return ans;
  }
};