#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int n, max_load;
int load = 0;
vector<vector<int>> distances{};
vector<int> stops{};
vector<bool> visited{};
int min_dist = numeric_limits<int>::max();
vector<vector<int>> mins{};
int current_dist = 0;

void mins_init() {
  mins.resize(2 * n + 1, vector<int>(2 * n + 1));
  for (int i = 0; i <= 2 * n; i++) {
    for (int j = 0; j <= 2 * n; j++) {
      mins[i][j] = distances[i][j];
    }
  }

  for (int k = 0; k <= 2 * n; k++) {
    for (int i = 0; i <= 2 * n; i++) {
      for (int j = 0; j <= 2 * n; j++) {
        if (mins[i][j] > mins[i][k] + mins[k][j]) {
          mins[i][j] = mins[i][k] + mins[k][j];
        }
      }
    }
  }
}

bool check(int i) {
  if (visited[i])
    return false;
  if (i > n) {
    if (!visited[i - n])
      return false;
  } else {
    if (load + 1 > max_load)
      return false;
  }

  return true;
}

void update(int stop) {
  min_dist = min(min_dist, current_dist + distances[stop][0]);
}

void backtrack_try(int i) {
  for (int next_stop = 1; next_stop <= 2 * n; next_stop++) {
    if (check(next_stop)) {
      stops[i] = next_stop;
      visited[next_stop] = 1;
      current_dist += distances[stops[i - 1]][next_stop];
      if (next_stop <= n) {
        load++;
      } else {
        load--;
      }

      if (i == 2 * n) {
        update(next_stop);
      } else {
        // if (current_dist + distances[next_stop][0] < min_dist) {
        if (current_dist + mins[next_stop][0] < min_dist) {
          backtrack_try(i + 1);
        }
      }

      if (next_stop <= n) {
        load--;
      } else {
        load++;
      }
      visited[next_stop] = 0;
      current_dist -= distances[stops[i - 1]][next_stop];
    }
  }
}

int main() {
  cin >> n >> max_load;
  distances.resize(2 * n + 1, vector<int>(2 * n + 1));
  visited.resize(2 * n + 1);
  stops.resize(2 * n + 1);

  for (int i = 0; i <= 2 * n; i++) {
    for (int j = 0; j <= 2 * n; j++) {
      cin >> distances[i][j];
    }
  }

  mins_init();

  backtrack_try(1);
  cout << min_dist << endl;
}
