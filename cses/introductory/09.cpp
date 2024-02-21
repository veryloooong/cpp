#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin >> n;
  ll ans = 1;
  while (n--)
    ans = (ans << 1) % MOD;
  cout << ans << "\n";
}