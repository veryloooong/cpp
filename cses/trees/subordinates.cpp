#include <bits/stdc++.h>

using namespace std;

constexpr size_t MAXN = 2e5;

vector<int> tree[MAXN + 1]; // for some fucking reason array<vector<int>,
                            // MAXN+1> doesn't compile on cses what the fuck bro
                            // asfjbnfidsjnsigndsjin
array<int, MAXN> ans;

void dfs(int u) {
  ans[u] = 1;
  if (tree[u].empty())
    return;
  for (auto &v : tree[u]) {
    dfs(v);
    ans[u] += ans[v];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    p--;
    tree[p].push_back(i);
  }

  dfs(0);

  for (int i = 0; i < n; ++i) {
    cout << ans[i] - 1 << " ";
  }

  return 0;
}
