#include <cstdint>
#include <ios>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;

constexpr ll MOD = 1e9 + 7; // NOLINT

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  constexpr auto flip = [](int n) { return n == 1 ? 2 : 1; };

  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> side(n, 0);
  bool is_bipartite = true;
  queue<int> q;

  for (int node = 0; node < n; ++node) {
    if (side[node] == 0) {
      q.push(node);
      side[node] = 1;
      while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
          if (side[u] == 0) {
            side[u] = flip(side[v]);
            q.push(u);
          } else {
            is_bipartite &= (side[u] != side[v]);
          }
        }
      }
    }
  }

  if (is_bipartite)
    for (auto x : side)
      cout << x << " ";
  else
    cout << "IMPOSSIBLE";
}

/*  */