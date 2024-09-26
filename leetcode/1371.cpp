#include <algorithm>
#include <array>
#include <bitset>
#include <limits>
#include <string>

class Solution {
public:
  int findTheLongestSubstring(std::string s) {
    std::bitset<8> bitmask{};
    std::array<int, 32> maskMap{};
    std::fill(maskMap.begin(), maskMap.end(), std::numeric_limits<int>::min());
    maskMap[0] = -1;

    int maxLength = 0;

    for (int i = 0, n = s.length(); i < n; i++) {
      char ch = s[i];
      switch (ch) {
      case 'a':
        bitmask.flip(0);
        break;
      case 'e':
        bitmask.flip(1);
        break;
      case 'i':
        bitmask.flip(2);
        break;
      case 'o':
        bitmask.flip(3);
        break;
      case 'u':
        bitmask.flip(4);
        break;
      }

      int previousIndex = maskMap[bitmask.to_ullong()];
      if (previousIndex == std::numeric_limits<int>::min()) {
        maskMap[bitmask.to_ullong()] = i;
      } else {
        maxLength = std::max(maxLength, i - previousIndex);
      }
    }

    return maxLength;
  }
};