#include <algorithm>
#include <vector>

class Solution {
public:
  int nthUglyNumber(int n) {
    std::vector<int> uglyNumbers{1};
    int l1 = 0;
    int l2 = 0;
    int l3 = 0;

    for (int i = 0; i < n; i++) {
      int num1 = uglyNumbers[l1] * 2;
      int num2 = uglyNumbers[l2] * 3;
      int num3 = uglyNumbers[l3] * 5;
      int nextNum = std::min({num1, num2, num3});

      if (nextNum == num1)
        l1++;
      if (nextNum == num2)
        l2++;
      if (nextNum == num3)
        l3++;
      uglyNumbers.push_back(nextNum);
    }

    return uglyNumbers.back();
  }
};