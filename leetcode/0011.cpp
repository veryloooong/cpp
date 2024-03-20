#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int area = INT32_MIN;
    size_t lhs = 0;
    size_t rhs = height.size() - 1;

    while (lhs < rhs) {
      const int current_area = min(height[lhs], height[rhs]) * (rhs - lhs);
      area = max(area, current_area);
      if (height[lhs] < height[rhs])
        lhs++;
      else
        rhs--;
    }

    return area;
  }
};
