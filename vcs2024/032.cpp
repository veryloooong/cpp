#include <cstdint>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int maxN = 2e5 + 5;
const int inf = 1e10;
int n;
int xs[maxN];
int ys[maxN];
int xi[maxN];
int yi[maxN];
vector<int> xx, yy;
vector<int> xxi[maxN], yyi[maxN];
bool check_pushed_xs[maxN][3], check_pushed_ys[maxN][3];
bool visited[maxN];
int dis[maxN];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> xs[i];
    xx.push_back(xs[i]);
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ys[i];
    yy.push_back(ys[i]);
  }

  sort(xx.begin(), xx.end());
  sort(yy.begin(), yy.end());

  xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
  yy.resize(unique(yy.begin(), yy.end()) - yy.begin());

  for (int i = 1; i <= n; i++) {
    xi[i] = lower_bound(xx.begin(), xx.end(), xs[i]) - xx.begin();
    yi[i] = lower_bound(yy.begin(), yy.end(), ys[i]) - yy.begin();
    xxi[xi[i]].push_back(i);
    yyi[yi[i]].push_back(i);
  }

  for (int i = 0; i <= n; i++) {
    check_pushed_xs[i][0] = false;
    check_pushed_xs[i][1] = false;
    check_pushed_xs[i][2] = false;
    check_pushed_ys[i][0] = false;
    check_pushed_ys[i][1] = false;
    check_pushed_ys[i][2] = false;
    visited[i] = false;
    dis[i] = inf;
  }

  int ans = 0;
  dis[1] = 0;
  priority_queue<pair<int, int>> q;
  q.push(make_pair(0, 1));
  while (!q.empty()) {
    auto p = q.top();
    q.pop();
    int d = -p.first;
    int node = p.second;
    // cout << "processing node " << node << " with dis " << d << '\n';
    if (visited[node])
      continue;
    visited[node] = true;
    ans += d;
    // cout << "Added node " << node << " with cost " << d << '\n';
    if (!check_pushed_xs[xi[node]][0]) {
      check_pushed_xs[xi[node]][0] = true;
      for (auto u : xxi[xi[node]]) {
        if (u == node)
          continue;
        if (!visited[u] && dis[u] > 0) {
          q.push(make_pair(0, u));
          dis[u] = 0;
          // cout << "push node " << u << " with dis " << dis[u] << '\n';
        }
      }
    }
    if (xi[node] > 0 && !check_pushed_xs[xi[node] - 1][1]) {
      check_pushed_xs[xi[node] - 1][1] = true;
      for (auto u : xxi[xi[node] - 1]) {
        if (u == node)
          continue;
        if (!visited[u] && dis[u] > abs(xx[xi[node]] - xx[xi[node] - 1])) {
          dis[u] = abs(xx[xi[node]] - xx[xi[node] - 1]);
          q.push(make_pair(-dis[u], u));
          // cout << "push node " << u << " with dis " << dis[u] << '\n';
        }
      }
    }
    if (xi[node] < (int)(xx.size() - 1) && !check_pushed_xs[xi[node] + 1][2]) {
      check_pushed_xs[xi[node] + 1][2] = true;
      for (auto u : xxi[xi[node] + 1]) {
        if (u == node)
          continue;
        if (!visited[u] && dis[u] > abs(xx[xi[node]] - xx[xi[node] + 1])) {
          dis[u] = abs(xx[xi[node]] - xx[xi[node] + 1]);
          q.push(make_pair(-dis[u], u));
        }
      }
    }

    if (!check_pushed_ys[yi[node]][0]) {
      check_pushed_ys[yi[node]][0] = true;
      for (auto u : yyi[yi[node]]) {
        if (u == node)
          continue;
        if (!visited[u] && dis[u] > 0) {
          q.push(make_pair(0, u));
          dis[u] = dis[node];
          // cout << "push node " << u << " with dis " << dis[u] << '\n';
        }
      }
    }

    if (yi[node] > 0 && !check_pushed_ys[yi[node] - 1][1]) {
      check_pushed_ys[yi[node] - 1][1] = true;
      for (auto u : yyi[yi[node] - 1]) {
        if (u == node)
          continue;
        if (!visited[u] && dis[u] > abs(yy[yi[node]] - yy[yi[node] - 1])) {
          dis[u] = abs(yy[yi[node]] - yy[yi[node] - 1]);
          q.push(make_pair(-dis[u], u));
          // cout << "push node " << u << " with dis " << dis[u] << '\n';
        }
      }
    }

    if (yi[node] < (int)(yy.size() - 1) && !check_pushed_ys[yi[node] + 1][2]) {
      check_pushed_ys[yi[node] + 1][2] = true;
      for (auto u : yyi[yi[node] + 1]) {
        if (u == node)
          continue;
        if (!visited[u] && dis[u] > abs(yy[yi[node]] - yy[yi[node] + 1])) {
          dis[u] = abs(yy[yi[node]] - yy[yi[node] + 1]);
          q.push(make_pair(-dis[u], u));
          // cout << "push node " << u << " with dis " << dis[u] << '\n';
        }
      }
    }
  }
  cout << ans << '\n';
}
signed main() {
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  ios_base::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
  solve();
  return 0;
}