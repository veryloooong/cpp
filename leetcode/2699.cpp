#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  modifiedGraphEdges(int n, std::vector<std::vector<int>> &edges, int source,
                     int destination, int target) {
    std::vector<std::vector<edge_t>> graph(n);

    for (auto &&edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int weight = edge[2];
      if (weight == -1)
        continue;

      graph[u].emplace_back(v, weight);
      graph[v].emplace_back(u, weight);
    }

    int dist = dijkstra(graph, source, destination);
    if (dist < target)
      return {};
    else if (dist == target) {
      for (auto &edge : edges)
        if (edge[2] == -1)
          edge[2] = MAX_W;
      return edges;
    }

    for (int i = 0; i < edges.size(); i++) {
      const int u = edges[i][0];
      const int v = edges[i][1];
      int &weight = edges[i][2];
      if (weight > -1)
        continue;
      weight = 1;
      graph[u].emplace_back(v, 1);
      graph[v].emplace_back(u, 1);
      dist = dijkstra(graph, source, destination);
      if (dist <= target) {
        weight += target - dist;
        for (int j = i + 1; j < edges.size(); j++)
          if (edges[j][2] == -1)
            edges[j][2] = MAX_W;
        return edges;
      }
    }

    return {};
  }

private:
  // (b, weight_ab)
  using edge_t = std::pair<int, int>;
  static constexpr int MAX_W = 2'000'000'000;

  // return weight from src to dst
  int dijkstra(std::vector<std::vector<edge_t>> &graph, int src, int dst) {
    std::vector<int> dist(graph.size(), INT32_MAX);
    auto edge_comp_t = [](edge_t a, edge_t b) { return a.second > b.second; };
    std::priority_queue<edge_t, std::vector<edge_t>, decltype(edge_comp_t)>
        heap(edge_comp_t);

    dist[src] = 0;
    heap.emplace(src, 0);

    while (!heap.empty()) {
      const auto [u, distance] = heap.top();
      heap.pop();

      if (distance > dist[u])
        continue;
      for (const auto &[v, weight] : graph[u]) {
        if (distance + weight < dist[v]) {
          dist[v] = distance + weight;
          heap.emplace(v, dist[v]);
        }
      }
    }

    return dist[dst];
  }
};