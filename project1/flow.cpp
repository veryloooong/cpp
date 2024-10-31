#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

int bfs_flow(int s, int t, std::vector<int> &parent,
             std::vector<std::vector<int>> &adj,
             std::vector<std::vector<int>> &capacity) {
  std::fill(parent.begin(), parent.end(), 0);
  parent[s] = -1;
  std::queue<std::pair<int, int>> q{};
  q.push({s, std::numeric_limits<uint16_t>::max()});

  while (!q.empty()) {
    int current = q.front().first;
    int flow = q.front().second;
    q.pop();

    for (int &v : adj[current]) {
      if (parent[v] == 0 && capacity[current][v] > 0) {
        parent[v] = current;
        int new_flow = std::min(flow, capacity[current][v]);
        if (v == t)
          return new_flow;
        q.push({v, new_flow});
      }
    }
  }

  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  int s, t;

  std::cin >> s >> t;
  std::vector<std::vector<int>> capacity(n + 1, std::vector<int>(n + 1));
  std::vector<std::vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    capacity[u][v] = w;
    capacity[v][u] = 0;
    adj[u].push_back(v);
  }

  std::vector<int> parent(n + 1, 0);
  int flow = 0;
  int new_flow;

  while ((new_flow = bfs_flow(s, t, parent, adj, capacity)) > 0) {
    flow += new_flow;
    int current = t;
    while (current != s) {
      int prev = parent[current];
      capacity[current][prev] += new_flow;
      capacity[prev][current] -= new_flow;
      current = prev;
    }
  }

  std::cout << flow << std::endl;
}