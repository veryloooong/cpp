#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;

constexpr ll MOD = 1e9 + 7; // NOLINT
constexpr size_t MAXN = 2e5;

vector<vector<int>> adj;
array<int, MAXN> depth{};

void dfs(int u, int parent) {
  for (auto v : adj[u])
    if (v != parent) {
      depth[v] = depth[u] + 1;
      dfs(v, u);
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  int b = 0;

  adj.resize(n);

  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(0, -1);
  for (int i = 0; i < n; ++i)
    if (depth[i] > depth[b])
      b = i;

  depth[b] = 0;

  dfs(b, -1);
  for (int i = 0; i < n; ++i)
    if (depth[i] > depth[b])
      b = i;

  cout << depth[b] << endl;

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */