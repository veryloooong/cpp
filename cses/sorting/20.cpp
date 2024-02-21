#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n, x, ans = 0;
  vector<ll> arr{};
  cin >> n >> x;
  ll e;
  for (int i = 0; i < n; ++i) {
    cin >> e;
    arr.push_back(e);
  }

  sort(arr.begin(), arr.end());

  ll lhs = 0, rhs = n - 1;
  while (lhs <= rhs) {
    if (arr[lhs] + arr[rhs] <= x)
      lhs++;
    rhs--;
    ans++;
  }

  cout << ans << endl;
}