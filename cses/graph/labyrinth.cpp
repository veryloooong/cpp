#include <bits/stdc++.h>
#include <utility>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;

// constexpr ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }

  typedef pair<int, int> coord;

  coord unvisited = {-1, -1};

  array<coord, 4> moves{
      make_pair(1, 0),
      make_pair(-1, 0),
      make_pair(0, 1),
      make_pair(0, -1),
  };

  string dirs{"DURL"};

  auto move_to_dir = [&](coord mov) {
    for (int i = 0; i < 4; ++i) {
      if (mov == moves[i]) {
        return dirs[i];
      }
    }
    return '?';
  };

  // vector<vector<bool>> visited(n, vector<bool>(m, false));

  vector<vector<coord>> prev(n, vector<coord>(m, unvisited));

  coord start{};

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'A') {
        start = make_pair(i, j);
        break;
      }
    }
  }

  queue<coord> q{};

  q.push(start);
  prev[start.first][start.second] = start;

  while (!q.empty()) {
    coord cur = q.front();
    q.pop();
    for (auto d : moves) {
      coord nxt = make_pair(cur.first + d.first, cur.second + d.second);
      if (nxt.first < 0 || nxt.first >= n || nxt.second < 0 || nxt.second >= m)
        continue;
      char ch = grid[nxt.first][nxt.second];

      if (ch == 'B') {
        cout << "YES\n";
        prev[nxt.first][nxt.second] = cur;

        vector<coord> path{};
        auto pos = nxt;
        while (pos != start) {
          path.push_back(pos);
          pos = prev[pos.first][pos.second];
        }
        cout << path.size() << '\n';
        reverse(path.begin(), path.end());
        for (coord d : path) {
          coord mov = make_pair(d.first - pos.first, d.second - pos.second);
          cout << move_to_dir(mov);
          pos = d;
        }
        cout << endl;
        return 0;
      }

      if (ch == '.' && prev[nxt.first][nxt.second] == unvisited) {
        q.push(nxt);
        prev[nxt.first][nxt.second] = cur;
      }
    }
  }

  cout << "NO\n";
  return 0;
}
