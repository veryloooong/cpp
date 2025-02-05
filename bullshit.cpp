#include <cstdio>

using namespace std;

inline int f(int x) {
  static int a = 10;
  return x = a;
}

void for_each(int *arr, int n, void (*func)(int &a)) {
  for (int i = 0; i < n; i++) {
    func(*(arr + i));
  }
}

int main() {
  int x, y = 5, z = 10;
  x = y++ + 2 * (y + z) + ++z;
  printf(" x= %d y= %d  z= %d ", x, y, z);
}