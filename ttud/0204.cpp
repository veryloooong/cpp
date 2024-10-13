#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int clients, trucks, capacity;
int current_distance = 0;
int min_dist = numeric_limits<int>::max();
vector<int> demand{};
vector<int> capacities{};
vector<vector<int>> distances{};
vector<bool> visited{};

bool check() {}

void update() {}

void backtrack(int k) {}

int main() {
  cin >> clients >> trucks >> capacity;
  demand.resize(clients + 1);
  visited.resize(clients + 1, false);
  capacities.resize(trucks);

  for (int i = 1; i <= clients; i++) {
    cin >> demand[i];
  }
  distances.resize(clients + 1, vector<int>(clients + 1));
  for (int i = 0; i <= clients; i++) {
    for (int j = 0; j <= clients; j++) {
      cin >> distances[i][j];
    }
  }

  backtrack(1);
  cout << min_dist << endl;

  return 0;
}