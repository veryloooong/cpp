#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int n, trucks, maxQ;
vector<int> req{};
vector<vector<int>> d{};
int min_dist = numeric_limits<int>::max();
// do things
vector<int> first{};
vector<int> nexts{};
vector<bool> visited{};
vector<int> load{};
int dist = 0;
int used = 0;
int segments = 0;
int curr = 0;
int num_trucks_used = 0;
int lbound = numeric_limits<int>::max();

bool check_x(int k, int v) {
  if (v > 0 && visited[v])
    return false;

  if (load[k] + req[v] > maxQ)
    return false;

  return true;
}

bool check_y(int k, int v) {
  if (v == 0)
    return true;
  if (load[k] + req[v] > maxQ)
    return false;
  if (visited[v])
    return false;
  return true;
}

void backtrack_x(int s, int k) {
  if (s == 0) {
    if (k < trucks) {
      backtrack_x(first[k + 1], k + 1);
    }
    return;
  }

  for (int v = 0; v <= n; v++) {
    if (check_x(k, v)) {
      nexts[s] = v;
      visited[v] = true;
      dist += d[s][v];
      load[k] += req[v];
      segments++;

      if (v > 0) {
        if (dist + (n + num_trucks_used - segments) * lbound < min_dist) {
          backtrack_x(v, k);
        }
      } else {
        if (k == trucks) {
          if (segments == n + num_trucks_used) {
            if (dist < min_dist)
              min_dist = dist;
          }
        } else {
          if (dist + (n + num_trucks_used - segments) * lbound < min_dist) {
            backtrack_x(first[k + 1], k + 1);
          }
        }
      }

      visited[v] = false;
      dist -= d[s][v];
      load[k] -= req[v];
      segments--;
    }
  }
}

void backtrack_y(int k) {
  curr = k;
  if (first[k - 1] > 0)
    curr = first[k - 1] + 1;

  for (int v = curr; v <= n; v++) {
    if (check_y(k, v)) {
      first[k] = v;
      if (v > 0)
        segments++;
      visited[v] = true;
      load[k] += req[v];
      dist += d[0][v];

      if (k < trucks)
        backtrack_y(k + 1);
      else {
        num_trucks_used = segments;
        backtrack_x(first[1], 1);
      }

      visited[v] = false;
      load[k] -= req[v];
      dist -= d[0][v];
      if (v > 0)
        segments--;
    }
  }
}

int main() {
  cin >> n >> trucks >> maxQ;
  req.resize(n + 1);
  first.resize(trucks + 1, 0);
  nexts.resize(n + 1, 0);
  visited.resize(n + 1);
  load.resize(trucks + 1, 0);
  for (int i = 1; i <= n; i++)
    cin >> req[i];

  d.resize(n + 1, vector<int>(n + 1));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      cin >> d[i][j];
      if (i != j && d[i][j] < lbound)
        lbound = d[i][j];
    }
  }

  backtrack_y(1);
  cout << min_dist;
}