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

vector<int> gray_code(int n) {
  bitset<16> bs{0};

  function<int(int)> lsb = [](int x) { return x & -x; };

  vector<int> arr;
  arr.reserve(1 << n);
  arr.push_back(bs.to_ulong());
  for (int i = 1, beeg = 1 << n; i < beeg; ++i) {
    auto tmp = bitset<16>{static_cast<ull>(lsb(i))};
    bs ^= tmp;
    arr.push_back(bs.to_ulong());
  }

  return arr;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto res = gray_code(2);
  for (const auto &x : res) {
    cout << x << " ";
  }

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */