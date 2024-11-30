#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  // do thi, do thi nguoc
  vector<vector<int>> graph(n + 1), graph_rev(n + 1);
  // thu tu tham dinh
  vector<bool> visited(n + 1, false);
  // low
  vector<int> low(n + 1);
  // hien tai
  vector<int> comps{};
  int scc_count = 0;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph_rev[v].push_back(u);
  }

  vector<int> order{};

  function<void(int, vector<int> &, vector<vector<int>> &)> dfs =
      [&](int u, vector<int> &find, vector<vector<int>> &g) {
        visited[u] = true;
        for (auto v : g[u]) {
          if (!visited[v]) {
            dfs(v, find, g);
          }
        }
        find.push_back(u);
      };

  auto scc = [&]() {
    for (int i = 1; i <= n; i++) {
      if (!visited[i])
        dfs(i, order, graph);
    }

    visited.assign(n + 1, false);
    reverse(order.begin(), order.end());

    for (int v : order) {
      if (!visited[v]) {
        vector<int> comp{};
        dfs(v, comp, graph_rev);
        scc_count++;
      }
    }
  };

  scc();

  cout << scc_count << endl;
}