#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  ll a;
  cin >> n;
  vector<ll> arr{};
  arr.reserve(n);

  for (int i = 0; i < n; ++i) {
    cin >> a;
    arr.push_back(a);
  }

  ll s1, s2;
  ll ans = INT_MAX;

  for (int i = 0; i < (1 << n); ++i) {
    s1 = 0;
    s2 = 0;
    for (int j = 0; j < n; j++) {
      if ((1 << j) & i)
        s1 += arr[j];
      else
        s2 += arr[j];
    }

    ans = min(ans, abs(s1 - s2));
  }

  cout << ans << '\n';
}