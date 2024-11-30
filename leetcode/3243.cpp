#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  typedef int32_t i32;
  typedef uint32_t u32;
  typedef int64_t i64;
  typedef uint64_t u64;

  std::vector<std::vector<int>> edges{};
  std::vector<int> dist{};

  void bfs(int start = 0) {
    std::queue<int> q{};
    q.push(start);
    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      for (const int v : edges[u]) {
        if (dist[u] + 1 < dist[v]) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
  }

public:
  std::vector<int>
  shortestDistanceAfterQueries(int n, std::vector<std::vector<int>> &queries) {
    edges.resize(n);
    dist.resize(n, n - 1);
    for (int i = 0; i < n - 1; i++) {
      edges[i].push_back(i + 1);
      dist[i] = i;
    }

    std::vector<int> ans{};
    ans.reserve(queries.size());

    for (const std::vector<int> &q : queries) {
      int u = q[0], v = q[1];
      edges[u].push_back(v);

      if (dist[u] + 1 < dist[v]) {
        dist[v] = dist[u] + 1;
        bfs(v);
      }

      ans.push_back(dist[n - 1]);
    }

    return ans;
  }
};

int main() {
  std::vector<std::vector<int>> queries{{1, 3}, {3, 5}};
  auto sol = Solution().shortestDistanceAfterQueries(6, queries);

  for (const auto &x : sol) {
    std::cout << x << ' ';
  }
  std::cout << std::endl;
}