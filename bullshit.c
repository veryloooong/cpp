#include <assert.h>
#include <stdio.h>

inline int f(int x) {
  static int a = 10;
  return x + a;
}

int main() {
  int x, y = 5, z = 10;
  x = y++ + 2 * (y + z) + ++z;
  printf(" x= %d y= %d  z= %d ", x, y, z);
}