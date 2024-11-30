#include <cstdint>
#include <fstream>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

constexpr i64 MOD = 1e9 + 7; // NOLINT

const char *inf = "input.txt";
const char *outf = "output.txt";

struct Bus {
  int c, d;
  Bus() : c(0), d(0) {}
  Bus(int c, int d) : c(c), d(d) {};
};

vector<Bus> buses{{0, 0}};
vector<vector<int>> graph{};
vector<int> dist;

int main() {
#ifndef ONLINE_JUDGE
  ifstream in(inf);
  ofstream out(outf);

  if (in.good()) {
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
  }
#endif

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int c, d;
    cin >> c >> d;
    buses.push_back({c, d});
  }

  graph.resize(n + 1);
  dist.resize(n + 1, 1e9);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>
      pq; // (cost, current city, bus)

  pq.push({0, 1, 1});

  while (!pq.empty()) {
    const auto [cost, city, bus] = pq.top();
    pq.pop();

    const Bus b = buses[bus];

    vector<int> visited(n + 1);
    queue<pair<int, int>> q{}; // (city, dist)
    q.push({city, 0});

    while (!q.empty()) {
      const auto [u, dst] = q.front();
      q.pop();

      if (visited[u] || dst > b.d)
        continue;
      visited[u] = true;

      for (const int v : graph[u]) {
        q.push({v, dst + 1});

        int new_cost = cost + b.c;
        pq.push({new_cost, v, bus});

        if (cost < dist[v]) {
          dist[v] = cost;
          pq.push({cost, v, bus});
        }
      }
    }
  }

  // solve

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */