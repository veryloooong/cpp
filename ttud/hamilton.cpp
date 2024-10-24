#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
  int vertices;
  vector<vector<int>> adj;

public:
  Graph(int vertices) {
    this->vertices = vertices;
    adj.resize(vertices);
  }

  void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bool has_hamiltonian_cycle() {
    vector<int> path(vertices, -1);
    path[0] = 0;

    return has_hamiltonian_cycle_util(path, 1);
  }

  bool has_hamiltonian_cycle_util(vector<int> &path, int pos) {
    if (pos == vertices) {
      // return path[0] == path[vertices - 1];
      return adj[path[pos - 1]][0] == path[0];
    }

    for (int v : adj[path[pos - 1]]) {
      if (path[v] == -1) {
        path[pos] = v;
        if (has_hamiltonian_cycle_util(path, pos + 1)) {
          return true;
        }
        path[pos] = -1;
      }
    }

    return false;
  }
};

int main() {
  int graphs;
  cin >> graphs;
  for (int i = 0; i < graphs; i++) {
    int n, m;
    cin >> n >> m;
    Graph graph(n);
    for (int j = 0; j < m; j++) {
      int u, v;
      cin >> u >> v;
      graph.add_edge(u - 1, v - 1);
    }

    cout << graph.has_hamiltonian_cycle() << endl;
  }
}