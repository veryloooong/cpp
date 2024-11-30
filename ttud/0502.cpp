#include <cstdint>
#include <fstream>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

constexpr i64 MOD = 1e9 + 7; // NOLINT

const char *inf = "input.txt";
const char *outf = "output.txt";

vector<int> num, low;
vector<vector<int>> adj;
int current = 0;

vector<pair<int, int>> bridges{};
unordered_set<int> pts{};

void dfs(int u, int p = -1) {
  low[u] = num[u] = ++current;
  int c = 0;

  for (int v : adj[u]) {
    if (v == p)
      continue;

    if (num[v]) {
      low[u] = min(low[u], num[v]);
    } else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= num[u] && p != -1) {
        pts.insert(u);
      }
      if (low[v] > num[u]) {
        bridges.push_back({u, v});
      }
    }
  }

  if (p == -1 && c > 1) {
    pts.insert(u);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  ifstream in(inf);
  ofstream out(outf);

  if (in.good()) {
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
  }
#endif

  int n, m;
  cin >> n >> m;

  num.resize(n + 1);
  low.resize(n + 1);
  adj.resize(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  for (int i = 1; i <= n; i++)
    if (!num[i])
      dfs(i);

  cout << pts.size() << ' ' << bridges.size();

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */