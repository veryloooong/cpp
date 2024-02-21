#include <bits/stdc++.h>

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

int missing_number(vector<int> &nums) {
  auto n = nums.size();
  if (n == 1) {
    return 1 - nums[0];
  }
  return (n * (n + 1) / 2 - accumulate(nums.begin(), nums.end(), 0));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> nums = {3, 0, 1};
  cout << missing_number(nums);

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */