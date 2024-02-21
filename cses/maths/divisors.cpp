#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr ll MOD = 1e9 + 7;

const ll MAXX = 1e6;
array<ll, MAXX + 1> arr{};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n, a;
  cin >> n;

  for (int i = 1; i <= MAXX; ++i) {
    for (int j = i; j <= MAXX; j += i)
      arr[j]++;
  }

  for (ll i = 0; i < n; ++i) {
    cin >> a;
    cout << arr[a] << '\n';
  }

  return 0;
}
