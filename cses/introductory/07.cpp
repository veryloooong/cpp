#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    ll a = i * i;
    cout << a * (a - 1) / 2 - 4 * (i - 1) * (i - 2) << "\n";
  }
}