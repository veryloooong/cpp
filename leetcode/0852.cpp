#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int peakIndexInMountainArray(vector<int> &arr) {
    int lhs = 0;
    int rhs = arr.size() - 1;

    while (lhs < rhs) {
      int mid = lhs + (rhs - lhs) / 2;
      if (arr[mid] < arr[mid + 1])
        lhs = mid + 1;
      else
        rhs = mid;
    }

    return lhs;
  }
};