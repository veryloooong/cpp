#include <array>
#include <chrono>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <queue>
#include <tuple>
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
  int n, m, r, c;
  cin >> n >> m >> r >> c;
  vector<vector<int>> mt(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mt[i][j];
    }
  }

  const array<pair<int, int>, 4> dirs = {
      make_pair(1, 0),
      make_pair(0, 1),
      make_pair(-1, 0),
      make_pair(0, -1),
  };

  using state_t = tuple<int, int, int>;
  queue<state_t> q;
  vector<vector<bool>> visited(n + 1, vector<bool>(m + 1));

  q.push(make_tuple(r, c, 0));
  while (!q.empty()) {
    const auto [x, y, steps] = q.front();
    q.pop();

    if (x < 1 || x > n || y < 1 || y > m) {
      cout << steps << endl;
      return;
    }
    if (mt[x][y] == 1)
      continue;
    if (visited[x][y])
      continue;

    visited[x][y] = true;
    for (auto [dx, dy] : dirs) {
      int nx = x + dx, ny = y + dy;
      q.push(make_tuple(nx, ny, steps + 1));
    }
  }

  cout << -1 << endl;
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

/*
 * "uuuuuuuuuuuuuuu" - Ceres Fauna (2021 - 2025)
 * imissfauna.com
 */
