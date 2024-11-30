#include <climits>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

// variables
int n, K, Q, M;
int d[20];
int c[20][20];
set<pair<int, int>> F;

// dp ?
vector<int> first;
vector<int> nxt;
vector<bool> visited;
vector<int> load;
int vehicles = 0;
int segments = 0;

long long ans = INT_MAX, cur = 0;

bool check_first(int k, int v) {
  if (v == 0)
    return true;

  if (load[k] + d[v] > Q)
    return false;

  if (visited[v])
    return false;

  return true;
}
bool check_nxt(int k, int v, int s) {
  if (v > 0 && visited[v])
    return false;
  if (load[k] + d[v] > Q)
    return false;
  if (F.find({s, v}) != F.end())
    return false;

  return true;
}

void init() {
  first.resize(K + 1);
  nxt.resize(n + 1);

  visited.resize(n + 1);
  load.resize(K + 1);
}

void try_nxt(int k, int v) {
  if (v == 0) {
    if (k < K)
      try_nxt(k + 1, first[k + 1]);
    return;
  }

  for (int nv = 0; nv <= n; nv++) {
    if (check_nxt(k, nv, v)) {
      // start backtrack
      nxt[v] = nv;
      visited[nv] = true;
      cur += c[v][nv];
      load[k] += d[nv];
      segments++;

      if (nv > 0) {
        try_nxt(k, nv);
      } else {
        if (k == K) {
          if (segments == n + vehicles) {
            ans = min(ans, cur);
          }
        } else {
          try_nxt(k + 1, first[k + 1]);
        }
      }

      // end backtrack
      visited[nv] = false;
      cur -= c[v][nv];
      load[k] -= d[nv];
      segments--;
    }
  }
}

void try_first(int k) {
  int start = 0;
  if (first[k - 1] > 0)
    start = first[k - 1] + 1;

  for (int v = start; v <= n; v++) {
    if (check_first(k, v)) {
      first[k] = v;

      // start backtrack
      if (v > 0)
        segments++;
      visited[v] = true;
      load[k] += d[v];
      cur = cur + c[0][v];

      if (k < K) {
        try_first(k + 1);
      } else {
        vehicles = segments;
        try_nxt(1, first[1]);
      }

      // end backtrack
      cur = cur - c[0][v];
      load[k] -= d[v];
      visited[v] = false;
      if (v > 0)
        segments--;
    }
  }
}

int main() {
  cin >> n >> K >> Q;
  for (int i = 1; i <= n; i++)
    cin >> d[i];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      cin >> c[i][j];
    }
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    F.insert({a, b});
    F.insert({b, a});
  }

  init();
  try_first(1);

  cout << ans << endl;
}