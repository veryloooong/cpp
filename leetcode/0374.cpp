#include <bits/stdc++.h>

using namespace std;

int guess(int num);

class Solution {
public:
  int guessNumber(int n) {
    int lhs = 1, rhs = n;
    int mid = 0;
    while (lhs < rhs) {
      mid = lhs + (rhs - lhs) / 2;
      int res = guess(mid);
      if (res == 0) {
        break;
      } else if (res == 1) {
        lhs = mid + 1;
      } else {
        rhs = mid;
      }
    }
    return mid;
  }

  int getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int len = 2; len <= n; ++len) {
      for (int start = 1; start <= n - len + 1; ++start) {
        int end = start + len - 1;
        dp[start][end] = INT_MAX;
        for (int pivot = start; pivot < end; ++pivot) {
          dp[start][end] = min(dp[start][end], pivot + max(dp[start][pivot - 1],
                                                           dp[pivot + 1][end]));
        }
      }
    }
    return dp[1][n];
  }
};