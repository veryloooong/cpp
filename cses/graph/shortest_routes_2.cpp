#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;

constexpr ll MOD = 1e9 + 7; // NOLINT

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<ll>> adj(n, vector<ll>(n, INT64_MAX));

  for (int i = 0; i < m; ++i) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--;
    b--;
    adj[a][b] = min(adj[a][b], c);
    adj[b][a] = min(adj[b][a], c);
  }

  for (int i = 0; i < n; ++i)
    adj[i][i] = 0;

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (adj[i][k] != INT64_MAX && adj[k][j] != INT64_MAX) {
          adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        }
      }
    }
  }

  for (int k = 0; k < q; ++k) {
    int a, b;
    ll d;
    cin >> a >> b;
    a--;
    b--;
    cout << ((d = adj[a][b]) == INT64_MAX ? -1 : d) << '\n';
  }

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */