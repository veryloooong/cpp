#include <iostream>
#include <limits>
#include <vector>

using namespace std;

static int load = 0;
static vector<vector<int>> d;
static vector<bool> visited;
static vector<int> path;
static vector<vector<int>> e2e_min_cost;
static int max_load;
static int min_cost = numeric_limits<int>::max();

void init_e2e_min() {
  e2e_min_cost.resize(d.size(),
                      vector<int>(d.size(), numeric_limits<int>::max()));

  for (int i = 0; i < d.size(); i++) {
    e2e_min_cost[i][i] = 0;
  }

  // Floyd-Warshall
  for (int k = 0; k < d.size(); k++) {
    for (int i = 0; i < d.size(); i++) {
      for (int j = 0; j < d.size(); j++) {
        if (e2e_min_cost[i][j] > e2e_min_cost[i][k] + e2e_min_cost[k][j]) {
          e2e_min_cost[i][j] = e2e_min_cost[i][k] + e2e_min_cost[k][j];
        }
      }
    }
  }
}

bool check(int v, int n) {
  if (visited[v]) {
    return false;
  }

  if (v > n) {
    if (!visited[v - n]) {
      return false;
    } else {
      if (load + 1 > max_load) {
        return false;
      }
    }
  }

  return true;
}

void update(int current_cost, int v) {
  if (current_cost + d[v][0] < min_cost) {
    min_cost = current_cost + d[v][0];
  }
}

void backtrack(int path_length, int n, int current_cost) {
  for (int v = 1; v <= 2 * n; v++) {
    if (check(v, n)) {
      path[path_length] = v;
      visited[v] = true;

      if (v <= n) {
        load++;
      } else {
        load--;
      }

      if (path_length == 2 * n) {
        update(current_cost, v);
      } else {
        backtrack(path_length + 1, n,
                  current_cost + d[path[path_length - 1]][v]);
      }

      if (v <= n) {
        load--;
      } else {
        load++;
      }

      visited[v] = false;
      current_cost -= d[path[path_length - 1]][v];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n >> max_load;

  d.resize(2 * n + 1, vector<int>(2 * n + 1));
  visited.resize(2 * n + 1, false);
  path.resize(2 * n + 1, 0);

  for (int i = 0; i <= 2 * n; i++) {
    for (int j = 0; j <= 2 * n; j++) {
      cin >> d[i][j];
    }
  }

  init_e2e_min();
  backtrack(1, n, 0);

  cout << min_cost << endl;
}