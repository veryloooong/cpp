#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;

// constexpr ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> dist(n, -1);
  queue<int> q;
  q.push(0);
  dist[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  if (dist[n - 1] == -1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  cout << dist[n - 1] + 1 << endl;
  int u = n - 1;
  vector<int> path;
  path.push_back(u + 1);
  while (u != 0) {
    for (int v : adj[u]) {
      if (dist[v] == dist[u] - 1) {
        u = v;
        path.push_back(u + 1);
        break;
      }
    }
  }
  reverse(path.begin(), path.end());
  for (int u : path) {
    cout << u << " ";
  }

  return 0;
}
