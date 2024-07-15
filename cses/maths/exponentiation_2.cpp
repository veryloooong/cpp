#include <cstdint>
#include <iostream>

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
constexpr ull expo(ull base, ull exponent, ull mod = MOD) {
  ull result = 1;

  while (exponent > 0) {
    if (exponent & 1) {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    exponent >>= 1;
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  while (n-- > 0) {
    ull a, b, c;
    cin >> a >> b >> c;
    b = expo(b, c, MOD - 1);
    cout << expo(a, b) << '\n';
  }

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */