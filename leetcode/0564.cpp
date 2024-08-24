#include <array>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

class Solution {
private:
  int64_t intToPalindrome(int64_t n, bool oddLen) {
    int64_t ans = n;

    if (oddLen)
      n /= 10;

    while (n) {
      ans = ans * 10 + n % 10;
      n /= 10;
    }
    return ans;
  }

public:
  std::string nearestPalindromic(std::string n) {
    int64_t num = stoll(n);
    int len = n.length();

    if (len == 1)
      return std::to_string(num - 1);

    if (n == "10" || n == "11")
      return std::string("9");

    int64_t leftSide = stoll(n.substr(0, (len + 1) / 2));
    bool oddLen = (len % 2) == 1;

    std::array<int64_t, 5> results{};
    results[0] = intToPalindrome(leftSide - 1, oddLen);
    results[1] = intToPalindrome(leftSide, oddLen);
    results[2] = intToPalindrome(leftSide + 1, oddLen);
    results[3] = std::pow(10, len - 1) - 1;
    results[4] = std::pow(10, len) + 1;

    int64_t ans = 0;
    int64_t minDiff = std::numeric_limits<int64_t>::max();

    for (const int64_t result : results) {
      if (result == num)
        continue;
      int64_t diff = std::llabs(result - num);
      if (diff < minDiff || (diff == minDiff && result < num)) {
        minDiff = diff;
        ans = result;
      }
    }

    return std::to_string(ans);
  }
};

int main() {
  std::string n = "1213";
  std::cout << Solution().nearestPalindromic(n) << std::endl;
}