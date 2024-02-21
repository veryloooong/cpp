#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;

constexpr ll MOD = 1e9 + 7; // NOLINT

vector<int> parent;
vector<bool> visited;
vector<vector<int>> adj;
int cs;
int ce;

bool dfs(int v, int par) {
  visited[v] = true;
  for (int u : adj[v]) {
    if (u == par)
      continue;
    if (visited[u]) {
      cs = v;
      ce = u;
      return true;
    }
    parent[v] = u;
    if (dfs(u, v))
      return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  adj.resize(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  visited.assign(n, false);
  parent.assign(n, -1);
  cs = -1;
  ce = -1;

  for (int i = 0; i < n; ++i) {
    if (!visited[i] && dfs(i, parent[i])) {
      break;
    }
  }

  if (cs == -1) {
    cout << "IMPOSSIBLE\n";
  } else {
    vector<int> cycle;
    cycle.push_back(cs);
    for (int v = ce; v != cs; v = parent[v]) {
      cycle.push_back(v);
    }
    cycle.push_back(cs);
    cout << cycle.size() << '\n';
    for (auto v : cycle)
      cout << v + 1 << ' ';
  }
}
