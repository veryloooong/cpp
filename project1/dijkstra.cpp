#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int dijkstra(int s, int t, vector<vector<pair<int, int>>> &adj) {
  vector<int> dist(adj.size(), numeric_limits<int>::max() / 2);
  dist[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, s});

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    for (auto &p : adj[u]) {
      int v = p.first;
      int w = p.second;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }

  if (dist[t] != numeric_limits<int>::max() / 2) {
    return dist[t];
  }

  return -1;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  int s, t;
  cin >> s >> t;

  int d = dijkstra(s, t, adj);
  cout << d << endl;
}