#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int n, K, Q;
vector<int> d;
vector<vector<int>> c;
vector<bool> visited;
vector<int> path;
int min_distance = numeric_limits<int>::max();

void backtrack(int truck, int current_location, int current_distance,
               int current_load) {
  if (truck > K)
    return;
  if (current_distance >= min_distance)
    return;
  if (current_load > Q)
    return;
  if (all_of(visited.begin() + 1, visited.end(), [](bool v) { return v; })) {
    min_distance = min(min_distance, current_distance + c[current_location][0]);
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      path[truck] = i;
      backtrack(truck, i, current_distance + c[current_location][i],
                current_load + d[i]);
      visited[i] = false;
    }
  }
  if (current_load > 0) {
    backtrack(truck + 1, 0, current_distance + c[current_location][0], 0);
  }
}

int main() {
  cin >> n >> K >> Q;
  d.resize(n + 1);
  c.resize(n + 1, vector<int>(n + 1));
  visited.resize(n + 1, false);
  path.resize(K + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      cin >> c[i][j];
    }
  }
  backtrack(1, 0, 0, 0);
  cout << min_distance << endl;
  return 0;
}