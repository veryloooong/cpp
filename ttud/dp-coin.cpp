#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n, x;
  std::cin >> n >> x;
  constexpr int MAXC = 1001;

  std::vector<int> d(n);
  for (int &c : d)
    std::cin >> c;

  std::vector<int> dp(x + 1, MAXC);
  for (int &c : d)
    if (c <= x)
      dp[c] = 1;

  for (int i = *std::min_element(d.begin(), d.end()); i <= x; i++) {
    for (const int &c : d)
      if (i - c >= 0) {
        dp[i] = std::min(dp[i], 1 + dp[i - c]);
      }
  }

  std::cout << (dp[x] == MAXC ? 0 : dp[x]) << '\n';
}