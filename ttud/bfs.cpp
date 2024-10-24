#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
private:
  int vertices;
  vector<vector<bool>> adj;

public:
  Graph(int vertices)
      : vertices(vertices), adj(vertices, vector<bool>(vertices)) {}

  Graph(int vertices, vector<vector<bool>> adj)
      : vertices(vertices), adj(adj) {}

  Graph(int vertices, vector<pair<int, int>> edges)
      : vertices(vertices), adj(vertices, vector<bool>(vertices)) {
    for (pair<int, int> edge : edges) {
      adj[edge.first][edge.second] = 1;
      adj[edge.second][edge.first] = 1;
    }
  }

  bool add_edge(int u, int v) {
    if (u < 0 || u >= vertices || v < 0 || v >= vertices) {
      return false;
    }
    if (adj[u][v] || adj[v][u]) {
      return false;
    }

    adj[u][v] = 1;
    adj[v][u] = 1;
    return true;
  }

  vector<int> bfs() {
    vector<bool> visited(vertices);
    vector<int> parent(vertices, -1);
    vector<int> order{};
    queue<int> q{};

    for (int i = 0; i < vertices; i++) {
      if (!visited[i]) {
        q.push(i);
        visited[i] = 1;
        while (!q.empty()) {
          int u = q.front();
          q.pop();
          order.push_back(u);
          for (int v = 0; v < vertices; v++) {
            if (adj[u][v] && !visited[v]) {
              q.push(v);
              visited[v] = 1;
              parent[v] = u;
            }
          }
        }
      }
    }

    return order;
  }

  vector<int> dfs() {
    vector<bool> visited(vertices);
    vector<int> parent(vertices, -1);
    vector<int> order{};

    function<void(int)> dfs_visit = [&](int u) {
      visited[u] = 1;
      order.push_back(u);
      for (int v = 0; v < vertices; v++) {
        if (adj[u][v] && !visited[v]) {
          parent[v] = u;
          dfs_visit(v);
        }
      }
    };

    for (int i = 0; i < vertices; i++) {
      if (!visited[i]) {
        dfs_visit(i);
      }
    }

    return order;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  Graph graph(n);

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    graph.add_edge(x, y);
  }

  vector<int> order = graph.dfs();
  for (int u : order) {
    cout << u + 1 << ' ';
  }

  return 0;
}