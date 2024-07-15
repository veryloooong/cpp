#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;

constexpr ll MOD = 1e9 + 7; // NOLINT

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, x;
  cin >> n >> x;
  constexpr int MAXC = 2e6;

  vector<int> coins(n);
  for (int i = 0; i < n; i++)
    cin >> coins[i];

  vector<int> dp(x + 1, MAXC);

  for (const auto &c : coins)
    if (c <= x)
      dp[c] = 1;

  for (int i = *min_element(coins.begin(), coins.end()); i <= x; i++) {
    for (const auto &c : coins) {
      if (i - c < 0)
        continue;

      dp[i] = min(dp[i], 1 + dp[i - c]);
    }
  }

  cout << (dp[x] == MAXC ? -1 : dp[x]) << endl;

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */