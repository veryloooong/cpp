#include <cassert>
#include <iostream>

int &bruh(int &x) { return x; }

int main() {
  int x = 5, y = 7;
  int *p = &x;
  int &r = x;
  *p += 2;
  y += r;
  std::cout << x << ' ' << y << std::endl;
}