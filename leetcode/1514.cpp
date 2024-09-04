#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  double maxProbability(int n, std::vector<std::vector<int>> &edges,
                        std::vector<double> &succProb, int start_node,
                        int end_node) {
    using edge_t = std::pair<int, double>;

    std::vector<std::vector<edge_t>> graph(n);
    for (int i = 0; i < edges.size(); i++) {
      const int a = edges[i][0];
      const int b = edges[i][1];
      const double prob = succProb[i];
      graph[a].emplace_back(b, prob);
      graph[b].emplace_back(a, prob);
    }

    std::function<bool(edge_t, edge_t)> edge_comp_t =
        [](const edge_t &a, const edge_t &b) { return a.second < b.second; };
    std::priority_queue<edge_t, std::vector<edge_t>, decltype(edge_comp_t)>
        heap(edge_comp_t);
    heap.emplace(start_node, 1.0);

    std::vector<bool> visited(n, false);
    while (!heap.empty()) {
      const edge_t current = heap.top();
      heap.pop();
      const int u = current.first;
      const double prob = current.second;

      if (u == end_node)
        return prob;
      if (visited[u])
        continue;
      visited[u] = true;

      for (const edge_t &edges : graph[u]) {
        if (visited[edges.first])
          continue;
        const int v = edges.first;
        const double edge_prob = edges.second;
        heap.emplace(v, prob * edge_prob);
      }
    }

    return 0.0;
  }
};

int main() {
  int n = 3;
  std::vector<std::vector<int>> edges{{0, 1}, {1, 2}, {0, 2}};
  std::vector<double> probs{0.5, 0.5, 0.2};
  std::cout << Solution().maxProbability(n, edges, probs, 0, 2) << std::endl;
}