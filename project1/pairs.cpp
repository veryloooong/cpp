#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<uint32_t>> adj(
      n + 1, std::vector<uint32_t>(n + 1, std::numeric_limits<int>::max()));
  for (int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    adj[u][v] = w;
  }

  for (int i = 0; i <= n; i++) {
    adj[i][i] = 0;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (adj[i][k] + adj[k][j] < adj[i][j]) {
          adj[i][j] = adj[i][k] + adj[k][j];
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cout << adj[i][j] << ' ';
    }
    std::cout << '\n';
  }
}