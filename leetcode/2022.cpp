#include <iterator>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> construct2DArray(std::vector<int> &original,
                                                 int m, int n) {
    if (m * n != original.size())
      return {};

    std::vector<std::vector<int>> ans{};
    ans.reserve(m);

    for (int i = 0; i < m; i++) {
      ans.push_back(std::vector<int>(std::next(original.begin(), n * i),
                                     std::next(original.begin(), n * (i + 1))));
    }

    return ans;
  }
};