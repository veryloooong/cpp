#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<ll> arr(n);
  for (ll i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  ll res = 0;
  for (ll i = 1; i < n; ++i) {
    res += max(0ll, arr[i - 1] - arr[i]);
    arr[i] = max(arr[i], arr[i - 1]);
  }
  cout << res;
  return 0;
}