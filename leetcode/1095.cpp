#include <bits/stdc++.h>

using namespace std;

class MountainArray {
public:
  int get(int index) {
    try {
      return array.at(index);
    } catch (out_of_range &e) {
      return -1;
    }
  }
  int length() { return array.size(); };

private:
  vector<int> array;
};

class Solution {
public:
  int findInMountainArray(int target, MountainArray &mountainArr) {
    int n = mountainArr.length();
    memo.assign(n, -1);
    int peak_idx = findPeak(mountainArr);

    int left_idx = findLeft(mountainArr, target, peak_idx);
    if (query(mountainArr, left_idx) == target)
      return left_idx;

    int right_idx = findRight(mountainArr, target, peak_idx + 1);
    if (query(mountainArr, right_idx) == target)
      return right_idx;

    return -1;
  }

private:
  vector<int> memo;

  int query(MountainArray &arr, int idx) {
    if (memo[idx] < 0)
      memo[idx] = arr.get(idx);
    return memo[idx];
  }

  int findPeak(MountainArray &arr) {
    int lhs = 0;
    int rhs = arr.length() - 1;

    while (lhs < rhs) {
      int mid = lhs + (rhs - lhs) / 2;
      if (query(arr, mid) < query(arr, mid + 1))
        lhs = mid + 1;
      else
        rhs = mid;
    }

    return lhs;
  }

  int findLeft(MountainArray &arr, int target, int rhs) {
    int lhs = 0;

    while (lhs < rhs) {
      int mid = lhs + (rhs - lhs) / 2;
      if (query(arr, mid) < target)
        lhs = mid + 1;
      else
        rhs = mid;
    }

    return lhs;
  }

  int findRight(MountainArray &arr, int target, int lhs) {
    int rhs = arr.length() - 1;

    while (lhs < rhs) {
      int mid = lhs + (rhs - lhs) / 2;
      if (query(arr, mid) > target)
        lhs = mid + 1;
      else
        rhs = mid;
    }

    return lhs;
  }
};