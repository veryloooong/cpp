#include <bits/stdc++.h>

using namespace std;

constexpr size_t MAXN = 2e5;

vector<vector<int>> adj;
array<int, MAXN> maxd{};

void dfs(int u, int parent) {
  for (auto v : adj[u])
    if (v != parent)
      dfs(v, u);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  adj.resize(n);

  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(0, -1);

  return 0;
}