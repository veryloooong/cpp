#include <algorithm>
#include <chrono>
#include <climits>
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

int N, K, D;
vector<vector<int>> C;
int Cmin = INT_MAX;
int Best = INT_MAX;
int Cur = 0;
int load = 0;
vector<i64> dists;
vector<bool> visited;
vector<int> path;

bool Check(int v, int k) {
  if (visited[v])
    return false;
  if (v > N) {
    if (!visited[v - N])
      return false;
    if (dists[v - N] + C[path[k - 1]][v] > D)
      return false;
  } else {
    if (load + 1 > K)
      return false;
  }

  return true;
}

void Update(int v) { Best = min(Best, Cur + C[v][0]); }

void Try(int k) {
  for (int v = 1; v <= 2 * N; v++) {
    if (Check(v, k)) {
      path[k] = v;
      for (int u = 1; u <= N; u++) {
        if (visited[u])
          dists[u] += C[path[k - 1]][v];
      }
      visited[v] = true;
      Cur += C[path[k - 1]][v];
      if (v <= N) {
        load++;
      } else {
        load--;
      }

      if (k == 2 * N) {
        Update(v);
      } else {
        if (Cur + Cmin * (2 * N - k) <= Best)
          Try(k + 1);
      }

      if (v <= N) {
        load--;
      } else {
        load++;
      }
      visited[v] = false;
      for (int u = 1; u <= N; u++) {
        if (visited[u])
          dists[u] -= C[path[k - 1]][v];
      }
      Cur -= C[path[k - 1]][v];
    }
  }
}

void solve() {
  cin >> N >> K >> D;
  C.resize(2 * N + 1, vector<int>(2 * N + 1));
  dists.resize(N + 1);
  visited.resize(2 * N + 1);
  path.resize(2 * N + 1);

  for (int i = 0; i <= 2 * N; i++) {
    for (int j = 0; j <= 2 * N; j++) {
      cin >> C[i][j];
      if (i != j) {
        Cmin = min(Cmin, C[i][j]);
      }
    }
  }

  Try(1);
  cout << (Best == INT_MAX ? -1 : Best);
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
