#include <iostream>
#include <unordered_map>

using namespace std;

constexpr long long MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  unordered_map<int, int> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }

  long long ans = 0;
  for (auto &[_, v] : a) {
    // ans += v * (v - 1) / 2;
    ans = (ans + v * (v - 1) / 2) % MOD;
  }

  cout << ans;
}