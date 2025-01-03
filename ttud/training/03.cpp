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

int N, K;
vector<vector<int>> d;
vector<int> visited;
vector<int> total;
vector<vector<int>> paths;
vector<int> fst, nxt;
int best = INT_MAX;

void init() {
  visited.resize(N + 1);
  d.resize(N + 1, vector<int>(N + 1));
  total.resize(K + 1);
  fst.resize(K + 1);
  nxt.resize(N + 1);
  paths.resize(K + 1, {0});
}

void try_nxt(int k) {}

bool check_fst(int k, int v) {
  if (v == 0)
    return true;
  if (visited[v])
    return false;
  return true;
}

void try_fst(int k) {
  int s = 0;
  if (fst[k - 1] > 0)
    s = fst[k - 1] + 1;

  for (int v = s; v <= N; v++) {
    if (check_fst(k, v)) {
      fst[k] = v;
      paths[k].push_back(v);
      visited[v] = true;

      visited[v] = false;
      paths[k].pop_back();
    }
  }
}

void solve() {
  cin >> N >> K;
  init();
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      cin >> d[i][j];
    }
  }
  try_fst(1);
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
