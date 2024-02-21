#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  ll a, b;

  typedef pair<ll, short> p;
  vector<p> arr;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    arr.push_back({a, 1});
    arr.push_back({b, -1});
  }

  sort(arr.begin(), arr.end(), [](p a, p b) {
    return a.first == b.first ? a.second < b.second : a.first < b.first;
  });

  int ans = 0, cur = 0;

  for (auto x : arr) {
    cur += x.second;
    ans = max(ans, cur);
  }

  cout << ans << endl;
}