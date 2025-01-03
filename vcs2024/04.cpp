#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
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
const char *expected = "expected.txt";

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << '(' << p.first << ',' << p.second << ')';
  return os;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &arr) {
  os << '[';
  for (int i = 0, n = arr.size(); i < n; i++) {
    os << arr[i] << (i < n - 1 ? ", " : "");
  }
  os << ']';

  return os;
}

struct yn_tf : numpunct<char> {
  string do_truename() const { return "YES"; }
  string do_falsename() const { return "NO"; }
};

void solve() {
  int n;
  cin >> n;
  vector<int> xs(n + 1), ys(n + 1);
  vector<int> xi(n + 1), yi(n + 1);
  vector<int> xx, yy;
  vector<vector<int>> xxi(2e5 + 3), yyi(2e5 + 3);

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
  xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
  sort(yy.begin(), yy.end());
  yy.resize(unique(yy.begin(), yy.end()) - yy.begin());

  for (int i = 1; i <= n; i++) {
    xi[i] = lower_bound(xx.begin(), xx.end(), xs[i]) - xx.begin();
    yi[i] = lower_bound(yy.begin(), yy.end(), ys[i]) - yy.begin();
    xxi[xi[i]].push_back(i);
    yyi[yi[i]].push_back(i);
  }

  vector<bool> visited(2e5 + 3, false);
  vector<i64> dist(2e5 + 3, 1e10);
  priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>>
      pq; // (dist, point index)
  vector<vector<bool>> check_pushed_xs(2e5 + 3,
                                       vector<bool>(3)); // now, before, after
  vector<vector<bool>> check_pushed_ys(2e5 + 3, vector<bool>(3));

  int ans = 0;
  dist[1] = 0;
  pq.push({0, 1});
  while (!pq.empty()) {
    const auto p = pq.top();
    pq.pop();
    const int d = p.first;
    const int v = p.second;

    if (visited[v])
      continue;

    visited[v] = true;
    ans += d;

    // check current
    if (!check_pushed_xs[xi[v]][0]) {
      check_pushed_xs[xi[v]][0] = true;
      for (const int u : xxi[xi[v]]) {
        if (u == v)
          continue;
        if (!visited[u] && dist[u] > 0) {
          dist[u] = 0;
          pq.push({0, u});
        }
      }
    }

    if (!check_pushed_ys[yi[v]][0]) {
      check_pushed_ys[yi[v]][0] = true;
      for (const int u : yyi[yi[v]]) {
        if (u == v)
          continue;
        if (!visited[u] && dist[u] > 0) {
          dist[u] = 0;
          pq.push({0, u});
        }
      }
    }

    // check before
    if (xi[v] > 0 && !check_pushed_xs[xi[v] - 1][1]) {
      check_pushed_xs[xi[v] - 1][1] = true;
      for (const int u : xxi[xi[v] - 1]) {
        if (u == v)
          continue;
        if (!visited[u] && dist[u] > abs(xx[xi[v]] - xx[xi[v] - 1])) {
          dist[u] = abs(xx[xi[v]] - xx[xi[v] - 1]);
          pq.push({dist[u], u});
        }
      }
    }

    if (yi[v] > 0 && !check_pushed_ys[yi[v] - 1][1]) {
      check_pushed_ys[yi[v] - 1][1] = true;
      for (const int u : yyi[yi[v] - 1]) {
        if (u == v)
          continue;
        if (!visited[u] && dist[u] > abs(yy[yi[v]] - yy[yi[v] - 1])) {
          dist[u] = abs(yy[yi[v]] - yy[yi[v] - 1]);
          pq.push({dist[u], u});
        }
      }
    }

    // check after
    if (xi[v] < (int)(xx.size() - 1) && !check_pushed_xs[xi[v] + 1][2]) {
      check_pushed_xs[xi[v] + 1][2] = true;
      for (const int u : xxi[xi[v] + 1]) {
        if (u == v)
          continue;
        if (!visited[u] && dist[u] > abs(xx[xi[v]] - xx[xi[v] + 1])) {
          dist[u] = abs(xx[xi[v]] - xx[xi[v] + 1]);
          pq.push({dist[u], u});
        }
      }
    }

    if (yi[v] < (int)(yy.size() - 1) && !check_pushed_ys[yi[v] + 1][2]) {
      check_pushed_ys[yi[v] + 1][2] = true;
      for (const int u : yyi[yi[v] + 1]) {
        if (u == v)
          continue;
        if (!visited[u] && dist[u] > abs(yy[yi[v]] - yy[yi[v] + 1])) {
          dist[u] = abs(yy[yi[v]] - yy[yi[v] + 1]);
          pq.push({dist[u], u});
        }
      }
    }
  }

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifndef ONLINE_JUDGE
  ifstream in(inf);
  ofstream out(outf);

  if (in.good()) {
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
  }
#endif

  cout.imbue(locale(cout.getloc(), new yn_tf));
  cout << boolalpha;
  cerr << boolalpha;

#ifndef ONLINE_JUDGE
  auto start = chrono::high_resolution_clock::now();
#endif

  solve();

#ifndef ONLINE_JUDGE
  auto end = chrono::high_resolution_clock::now();
  auto elapsed = end - start;
  cerr << "runtime: "
       << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count()
       << " ms" << endl;
#endif

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */
