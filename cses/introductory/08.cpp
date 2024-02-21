#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n, s;
  cin >> n;
  if ((s = n * (n + 1) / 2) % 2 == 1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    ll a = s / 2;
    vector<ll> arr1{}, arr2{};
    for (ll i = n; i >= 1; --i) {
      if (a >= i) {
        arr1.push_back(i);
        a -= i;
      } else
        arr2.push_back(i);
    }
    cout << arr1.size() << "\n";
    for (auto x : arr1)
      cout << x << " ";
    cout << "\n" << arr2.size() << "\n";
    for (auto x : arr2)
      cout << x << " ";
  }
}