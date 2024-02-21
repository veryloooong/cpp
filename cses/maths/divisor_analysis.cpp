#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;

constexpr ll MOD = 1e9 + 7; // NOLINT

ull expo(ull base, ull exponent) {
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

ull invrs(ull den) { return expo(den, MOD - 2); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, ull>> factors(n);

  ull num_divs = 1;
  ull sum_divs = 1;
  ull mul_divs = 1;

  for (int i = 0; i < n; ++i) {
    int p;
    ull k;
    cin >> p >> k;

    num_divs = (num_divs * (k + 1)) % MOD;

    // ull pow = 1, ms = 0;
    // for (ull j = 0; j <= k; ++j) {
    //   ms = (ms + pow) % MOD;
    //   pow = (pow * p) % MOD;
    // }

    // sum_divs = (sum_divs * ms) % MOD;

    sum_divs =
        (sum_divs * (expo(p, k + 1) - 1) % MOD * invrs(p - 1) % MOD) % MOD;

    factors.push_back({p, k});
  }

  bool is_square = true;
  ull divs = 1;
  for (auto [p, k] : factors) {
    if (k % 2 == 0 || !is_square) {
      divs = (divs * (k + 1)) % (MOD - 1);
    } else {
      divs = (divs * (k + 1) / 2) % (MOD - 1);
      is_square = false;
    }
  }

  for (auto [p, k] : factors) {
    if (is_square)
      k /= 2;
    mul_divs = (mul_divs * expo(p, k * divs % (MOD - 1))) % MOD;
  }

  cout << num_divs << " " << sum_divs << " " << mul_divs << endl;

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */