#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll x, y, r;
  cin >> x >> y;
  if ((r = max(x, y)) % 2 == 1) {
    if (x <= y)
      cout << r * r - x + 1;
    else
      cout << r * r - r + 1 - (r - y);
  } else {
    if (y <= x)
      cout << r * r - y + 1;
    else
      cout << r * r - r + 1 - (r - x);
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    solve();
}