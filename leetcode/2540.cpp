#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int getCommon(vector<int> &nums1, vector<int> &nums2) {
    size_t ptr1 = 0;
    size_t ptr2 = 0;
    size_t n1 = nums1.size();
    size_t n2 = nums2.size();

    while (ptr1 != n1 && ptr2 != n2) {
      if (nums1[ptr1] > nums2[ptr2])
        ptr2++;
      else if (nums1[ptr1] < nums2[ptr2])
        ptr1++;
      else
        return nums1[ptr1];
    }

    return -1;
  }
};