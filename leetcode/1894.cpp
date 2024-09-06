#include <numeric>
#include <vector>

class Solution {
public:
  int chalkReplacer(std::vector<int> &chalk, int k) {
    const long long sumChalks =
        std::accumulate(chalk.begin(), chalk.end(), 0LL);
    k %= sumChalks;
    for (int i = 0; i < chalk.size(); i++) {
      if (chalk[i] > k)
        return i;
      else
        k -= chalk[i];
    }
    return 0;
  }
};