#include <vector>

class Solution {
public:
  std::vector<int> xorQueries(std::vector<int> &arr,
                              std::vector<std::vector<int>> &queries) {
    std::vector<int> prefixXors(arr.size());
    std::vector<int> ans{};
    ans.reserve(queries.size());
    prefixXors[0] = arr[0];

    for (int i = 1; i < arr.size(); i++) {
      prefixXors[i] = prefixXors[i - 1] ^ arr[i];
    }

    for (const auto &q : queries) {
      const int a = q[0];
      const int b = q[1];
      ans.push_back((a == 0 ? 0 : prefixXors[a - 1]) ^ prefixXors[b]);
    }

    return ans;
  }
};