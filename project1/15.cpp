#include <array>
#include <iostream>

std::array<std::array<int, 1000>, 1000> binomial_memo{};

constexpr int MOD = 1e9 + 7;

int binomial(int n, int k) {
  if (k == 0 || k == n)
    return 1;

  if (binomial_memo[n][k])
    return binomial_memo[n][k];

  return binomial_memo[n][k] =
             (binomial(n - 1, k) + binomial(n - 1, k - 1)) % MOD;
}

void binomial_memo_init() {
  binomial_memo.fill(std::array<int, 1000>({}));

  for (int i = 0; i < 1000; i++) {
    binomial_memo[i][0] = binomial_memo[i][i] = 1;
  }
}

int main() {
  binomial_memo_init();

  int n, k;
  std::cin >> k >> n;
  std::cout << binomial(n, k) << std::endl;
}