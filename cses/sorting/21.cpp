#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr ll MOD = 1e9 + 7;

int main() {
  typedef multiset<ll, greater<ll>> ordset;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  ll e;
  cin >> n >> m;
  ordset h;
  ordset::iterator it;
  ll t;

  for (int i = 0; i < n; ++i) {
    cin >> e;
    h.insert(e);
  }

  for (int i = 0; i < m; ++i) {
    cin >> t;
    if ((it = h.lower_bound(t)) == h.end()) {
      cout << "-1\n";
    } else {
      cout << *it << "\n";
      h.erase(it);
    }
  }
}