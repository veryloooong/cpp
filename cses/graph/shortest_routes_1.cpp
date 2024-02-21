#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;

constexpr ll MOD = 1e9 + 7; // NOLINT

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;

  // vector<vector<ll>> adj(n, vector<ll>(n, -1));
  vector<vector<pair<int, ll>>> adj(n);

  for (int i = 0; i < m; ++i) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--;
    b--;
    adj[a].push_back({b, c});
  }

  typedef pair<ll, int> li;
  priority_queue<li, vector<li>, greater<>> pq;
  vector<ll> dist(n, INT64_MAX);
  dist[0] = 0;
  pq.push({0, 0});

  while (!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();
    if (d != dist[v])
      continue;

    for (auto [u, len] : adj[v]) {
      if (dist[v] + len < dist[u]) {
        dist[u] = dist[v] + len;
        pq.push({dist[u], u});
      }
    }
  }

  for (auto d : dist) {
    cout << d << " ";
  }

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */