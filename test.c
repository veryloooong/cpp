#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  if (n >= 100) {
    int cum = n;
    while (cum < 1000) {
      printf("%d ", cum);
      cum += n;
    }
  } else {
    int times = 100 / n;
    int cum = n * times;
    if (cum < 100)
      cum += n;
    while (cum < 1000) {
      printf("%d ", cum);
      cum += n;
    }
  }
  return 0;
}