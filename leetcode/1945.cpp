#include <iostream>
#include <string>

class Solution {
public:
  int getLucky(std::string s, int k) {
    k--;
    int current = 0;

    // First transform
    for (const char &ch : s) {
      int val = ch - 'a' + 1;
      current += val / 10 + val % 10;
    }

    while (k--) {
      int temp = 0;
      while (current > 0) {
        temp += current % 10;
        current /= 10;
      }
      current = temp;
    }

    return current;
  }
};

int main() {
  std::string s = "iiii";
  std::cout << Solution().getLucky(s, 1);
}