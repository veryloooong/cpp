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

constexpr size_t MAX_N = 2e5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int x, p;
  size_t n;
  cin >> x >> n;

  typedef set<int>::iterator it;
  typedef pair<int, size_t> light;

  set<int> lights{0, x};
  array<int, MAX_N> ans{};
  array<light, MAX_N + 2> arr{};

  arr[0] = {0, 0};
  arr[MAX_N + 1] = {x, 1};

  for (size_t i = 0; i < n; ++i) {
    cin >> p;
    light l = {p, i + 2};
    lights.insert(p);
    arr[i + 1] = l;
  }

  int best = 0;

  sort(arr.begin(), arr.end());

  for (size_t i = 0; i < MAX_N + 1; ++i) {
    best = max(best, arr[i + 1].first - arr[i].first);
  }

  sort(arr.begin(), arr.end(),
       [](light a, light b) { return a.second > b.second; });

  for (size_t i = 0; i < n; ++i) {
    ans[n - 1 - i] = best;
    it s = lights.find(arr[i].first);
    it f = next(s);
    it b = next(s, -1);
    best = max(best, *f - *b);
    lights.erase(s);
  }

  for (size_t i = 0; i < n; ++i)
    cout << ans[i] << " ";

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */