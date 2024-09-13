#include <bitset>
class Solution {
public:
  inline int minBitFlips(int start, int goal) {
    return std::bitset<32>(start ^ goal).count();
  }
};