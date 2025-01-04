#include <stdio.h>

inline int calc(int x) { return x + 3; }

int main(void) {
  int i = 10, j = 0;
  if (i || (j = i + 10))
    printf("%d", j);
}