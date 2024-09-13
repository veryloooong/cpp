#include <algorithm>
#include <bitset>
#include <string>
#include <vector>

class Solution {
public:
  int countConsistentStrings(std::string allowed,
                             std::vector<std::string> &words) {
    std::bitset<26> bitmask{};
    for (const char ch : allowed) {
      bitmask.set(static_cast<int>(ch) - 'a');
    }

    return std::count_if(
        words.begin(), words.end(), [&](const std::string word) {
          return std::all_of(word.begin(), word.end(), [&](const char ch) {
            return bitmask.test(static_cast<int>(ch) - 'a');
          });
        });
  }
};