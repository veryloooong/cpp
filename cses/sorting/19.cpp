#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, ans = 0, e;
  ll k;
  vector<ll> a{}, b{};

  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    cin >> e;
    a.push_back(e);
  }
  for (int i = 0; i < m; ++i) {
    cin >> e;
    b.push_back(e);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int ap = 0, bp = 0;
  while (ap < n) {
    while (bp < m && b[bp] < a[ap] - k)
      bp++;
    if (bp < m && a[ap] - k <= b[bp] && b[bp] <= a[ap] + k) {
      ans++;
      bp++;
    }
    ap++;
  }

  cout << ans << endl;

  return 0;
}