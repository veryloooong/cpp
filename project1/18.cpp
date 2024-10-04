#include <bitset>
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  std::bitset<20> bits{};

  for (size_t i = 0; i < (1 << n); i++) {
    bits = {i};
    bool bad = false;

    for (size_t k = 0; k < n - 1; k++) {
      if (bits.test(k) && bits.test(k + 1)) {
        bad = true;
        break;
      }
    }
    if (!bad)
      std::cout << bits.to_string().substr(20 - n) << "\n";
  }
}