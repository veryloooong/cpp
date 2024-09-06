#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

class Solution {
public:
  std::vector<int> missingRolls(std::vector<int> &rolls, int mean,
                                int missing) {
    int m = rolls.size();
    int missingSum =
        mean * (m + missing) - std::accumulate(rolls.begin(), rolls.end(), 0);
    if (missingSum < missing || missingSum > 6 * missing)
      return {};

    std::vector<int> missingRolls(missing, 0);
    int current = 0;
    while (current < missing && missingSum > (missing - current)) {
      missingRolls[current++] = 6;
      missingSum -= 6;
    }

    if (missingSum < (missing - current))
      missingRolls[current - 1] -= (missing - current - missingSum);

    std::replace(missingRolls.begin(), missingRolls.end(), 0, 1);

    return missingRolls;
  }
};

int main() {
  std::vector<int> rolls = {1, 1, 1};
  std::vector<int> missing = Solution().missingRolls(rolls, 3, 4);
  for (auto &x : missing)
    std::cout << x << " ";
}