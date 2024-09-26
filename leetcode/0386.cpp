#include <string>
#include <vector>

class Solution {
public:
  std::vector<int> lexicalOrder(int n) {
    std::vector<int> ans{};
    int current = 1;

    while (ans.size() < n) {
      ans.push_back(current);
      if (current * 10 <= n) {
        current *= 10;
      } else {
        while (current % 10 == 9 || current >= n)
          current /= 10;
        current++;
      }
    }

    return ans;
  }
};