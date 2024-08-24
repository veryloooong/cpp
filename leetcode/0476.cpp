#include <bit>
#include <cstdint>

class Solution {
public:
  int findComplement(int32_t num) {
    return static_cast<int32_t>(
        (1ULL << std::bit_width(static_cast<uint32_t>(num))) - num - 1);
  }
};