#include <bits/stdc++.h>
#include <exception>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;

constexpr ll MOD = 1e9 + 7; // NOLINT

static constexpr ull ct_sqrt(ull res, ull l, ull r) {
  if (l == r) {
    return r;
  } else {
    const auto mid = (r + l) / 2;

    if (mid * mid >= res) {
      return ct_sqrt(res, l, mid);
    } else {
      return ct_sqrt(res, mid + 1, r);
    }
  }
}

// Compile-time square root
static constexpr ull ct_sqrt(ull res) { return ct_sqrt(res, 1, res); } // NOLINT

// Binary exponential
constexpr ull expo(ull base, ull exponent) {
  ull result = 1;

  while (exponent > 0) {
    if (exponent & 1) {
      result = (result * base) % MOD;
    }
    base = (base * base) % MOD;
    exponent >>= 1;
  }
  return result;
}

int find_peak_element(vector<int> &nums) {
  size_t l = 0, r = nums.size();
  auto mid = l + (r - l) / 2;
  while (l <= r) {
    int left, right;
    try {
      left = nums.at(mid - 1);
    } catch (exception) {
      left = INT_MIN;
    }
    try {
      right = nums.at(mid + 1);
    } catch (exception) {
      right = INT_MIN;
    }

    if (nums[mid] > left && nums[mid] > right) {
      return mid;
    } else if (nums[mid] <= left) {
      r = mid;
    } else if (nums[mid] <= right) {
      l = mid;
    }

    mid = l + (r - l) / 2;
  }

  return mid;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
  cout << find_peak_element(nums);

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */