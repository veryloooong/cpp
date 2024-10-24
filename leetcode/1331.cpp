#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> arrayRankTransform(std::vector<int> &arr) {
    std::vector<int> tmp(arr);
    std::vector<int> rank(arr.size());
    std::iota(rank.begin(), rank.end(), 1);
    std::sort(tmp.begin(), tmp.end());

    for (size_t i = 1; i < tmp.size(); i++) {
      if (tmp[i] == tmp[i - 1])
        rank[i] = rank[i - 1];
      else
        rank[i] = rank[i - 1] + 1;
    }

    std::unordered_map<int, int> lookup{};
    for (size_t i = 0; i < tmp.size(); i++)
      lookup[tmp[i]] = rank[i];

    std::vector<int> result(arr.size());

    std::transform(arr.begin(), arr.end(), result.begin(),
                   [&lookup](int x) { return lookup[x]; });

    return result;
  }
};