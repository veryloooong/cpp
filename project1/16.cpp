#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> arr(n);
  std::iota(arr.begin(), arr.end(), 1);

  do {
    for (const int x : arr)
      std::cout << x << " ";
    std::cout << "\n";
  } while (std::next_permutation(arr.begin(), arr.end()));
}