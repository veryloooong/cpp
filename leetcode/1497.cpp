#include <unordered_map>
#include <vector>

class Solution {
public:
  bool canArrange(std::vector<int> &arr, int k) {
    std::unordered_map<int, int> remainderFreqs{};
    for (size_t i = 0; i < arr.size(); i++) {
      int remainder = arr[i] % k;
      if (remainder < 0) {
        remainder += k;
      }
      remainderFreqs[remainder]++;
    }

    for (auto &[remainder, freq] : remainderFreqs) {
      if ((remainder == 0 || 2 * remainder == k) && freq % 2 != 0) {
        return false;
      } else if (remainder != 0 && remainder != k - remainder &&
                 remainderFreqs[k - remainder] != freq) {
        return false;
      }
    }

    return true;
  }
};