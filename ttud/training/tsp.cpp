#include <algorithm>
#include <chrono>
#include <cstdint>
#include <fstream>
#include <iostream>
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

int N, Cmin;
vector<vector<int>> c;
vector<bool> visited;
vector<int> path;
int cur = 0, best = INT_MAX;

bool Check(int k, int v) {
  if (visited[v])
    return false;
  if (cur + c[path[k - 1]][v] > best)
    return false;

  return true;
}

void Try(int k) {
  for (int v = 1; v <= N; v++) {
    if (Check(k, v)) {
      path[k] = v;
      visited[v] = true;
      cur += c[path[k - 1]][v];

      if (k == N)
        best = min(cur, best);
      else if (cur + (N - k) * Cmin > best)
        Try(k + 1);

      cur -= c[path[k - 1]][v];
      visited[v] = false;
    }
  }
}

void solve() {
  cin >> N;
  c.resize(N + 1, vector<int>(N + 1));
  visited.resize(N + 1);
  path.resize(N + 1);

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> c[i][j];
      if (i != j)
        Cmin = min(Cmin, c[i][j]);
    }
  }

  Try(1);
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
