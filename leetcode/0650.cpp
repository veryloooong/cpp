class Solution {
public:
  int minSteps(int n) {
    if (n == 1)
      return 0;

    int ans = 0;
    int div = 2;

    while (n > 1) {
      while (n % div == 0) {
        ans += div;
        n /= div;
      }
      div++;
    }

    return ans;
  }
};