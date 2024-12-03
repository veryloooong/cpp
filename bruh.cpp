#include <iostream>

void nhapMang(int **&a, int &h, int &c) {
  printf("\n hay nhap so hang va so cot: ");
  scanf("%d%d", &h, &c);
  a = new int *[h];
  for (int i = 0; i < h; i++)
    a[i] = new int[c];
  for (int i = 0; i < h; i++)
    for (int j = 0; j < c; j++)
      scanf("%d", &a[i][j]);
}

void hienThiMang(int **a, int h, int c) {
  printf("mang la: ");
  for (int i = 0; i < h; i++)
    for (int j = 0; j < c; j++)
      printf("%d ", a[i][j]);
}

void xoaMang(int **&a, int h, __attribute__((unused)) int c) {
  for (int i = 0; i < h; i++) {
    delete[] a[i];
  }
  delete[] a;
}

int main() {
  int **b;
  int h, c;
  nhapMang(b, h, c);
  hienThiMang(b, h, c);
  xoaMang(b, h, c);
}