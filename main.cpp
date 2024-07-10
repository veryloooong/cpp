#include <array>
#include <iostream>

int main() {
  std::array<int, 10> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  for (const auto &x : arr) {
    std::cout << "array elem: " << x << '\n';
  }

  return 0;
}
