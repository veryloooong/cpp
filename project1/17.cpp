#include <iostream>

int fibonacci(int n) {
  if (n <= 1)
    return n;

  int a = 0, b = 1, c = a + b;

  for (int i = 2; i < n - 1; i++) {
    a = b;
    b = c;
    c = a + b;
  }

  return c;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << fibonacci(n);
}