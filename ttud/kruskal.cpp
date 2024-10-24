#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int u, v, w;
};

class Graph {
private:
  int vertices;
  vector<Edge> edges;
  vector<int> parent;
  vector<int> sz;

public:
  Graph(int vertices, vector<Edge> edges)
      : vertices(vertices), edges(edges), parent(vertices), sz(vertices) {
    sort(this->edges.begin(), this->edges.end(),
         [](const Edge &a, const Edge &b) { return a.w < b.w; });
  }

  void make_set() {
    for (int i = 0; i < vertices; i++) {
      parent[i] = i;
      sz[i] = 1;
    }
  }

  int find_set(int u) {
    return parent[u] == u ? u : parent[u] = find_set(parent[u]);
  }

  void union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u != v) {
      if (sz[u] < sz[v]) {
        swap(u, v);
      }
      parent[v] = u;
      sz[u] += sz[v];
    }
  }

  int kruskal() {
    make_set();
    int mst = 0;
    for (Edge edge : edges) {
      if (find_set(edge.u) != find_set(edge.v)) {
        mst += edge.w;
        union_set(edge.u, edge.v);
      }
    }
    return mst;
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<Edge> edges(m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    edges[i] = {u, v, w};
  }

  Graph graph(n, edges);
  cout << graph.kruskal() << endl;
}