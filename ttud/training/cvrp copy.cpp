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

int N, K, Q;
vector<vector<int>> C;
// vector<vector<bool>> block;
int best = INT_MAX, cur = 0, Cmin = INT_MAX;
vector<bool> visited;
vector<int> X, Y, load, D; // Y = first, X = next, D = client
int segs = 0;
int Trucks = 0;

bool CheckX(int k, int v, int s) {
  if (v > 0 && visited[v])
    return false;
  if (load[k] + D[v] > Q)
    return false;
  return true;
}

void TryX(int k, int s) {
  if (s == 0) {
    if (k < K)
      TryX(k + 1, Y[k + 1]);
    return;
  }
  for (int v = 0; v <= N; v++) { // next point s->v
    if (CheckX(k, v, s)) {
      X[s] = v;
      visited[v] = true;
      cur += C[s][v];
      load[k] += D[v];
      segs++;

      if (v > 0) { // go next
        if (cur + (N + Trucks - segs) * Cmin <= best)
          TryX(k, v);
      } else { // return
        if (k == K) {
          if (segs == N + Trucks)
            best = min(best, cur);
        } else if (cur + (N + Trucks - segs) * Cmin <= best)
          TryX(k + 1, Y[k + 1]);
      }

      segs--;
      load[k] -= D[v];
      cur -= C[s][v];
      visited[v] = false;
    }
  }
}

bool CheckY(int k, int v) {
  if (v == 0)
    return true;
  if (load[k] + D[v] > Q)
    return false;
  if (visited[v])
    return false;
  return true;
}

void TryY(int k) {
  int s = 0;
  if (Y[k - 1] > 0)
    s = Y[k - 1] + 1;
  for (int v = s; v <= N; v++) {
    if (CheckY(k, v)) {
      Y[k] = v;
      if (v > 0)
        segs++;
      visited[v] = true;
      cur += C[0][v];
      load[k] += D[v];

      if (k == K) {
        Trucks = segs;
        TryX(1, Y[1]);
      } else {
        TryY(k + 1);
      }

      load[k] -= D[v];
      cur -= C[0][v];
      visited[v] = false;
      if (v > 0)
        segs--;
    }
  }
}

void Init() {
  C.resize(N + 1, vector<int>(N + 1));
  // block.resize(N + 1, vector<bool>(N + 1));
  visited.resize(N + 1);
  load.resize(K + 1);
  Y.resize(K + 1);
  X.resize(N + 1);
  D.resize(N + 1);
}

void solve() {
  cin >> N >> K >> Q;
  Init();
  for (int i = 1; i <= N; i++)
    cin >> D[i];
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      cin >> C[i][j];
      if (i != j)
        Cmin = min(Cmin, C[i][j]);
    }
  }
  // cin >> F;
  // for (int i = 0; i < F; i++) {
  //   int u, v;
  //   cin >> u >> v;
  //   block[u][v] = true;
  //   block[v][u] = true;
  // }

  TryY(1);
  cout << best << endl;
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
