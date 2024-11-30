#include <algorithm>
#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
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

public:
  std::vector<std::vector<int>>
  validArrangement(std::vector<std::vector<int>> &pairs) {
    std::unordered_map<int, std::vector<int>> adj{};
    std::unordered_map<int, int> indegree, outdegree;

    for (const auto &edge : pairs) {
      int u = edge[0], v = edge[1];
      adj[u].push_back(v);
      outdegree[u]++;
      indegree[v]++;
    }

    int start_vertex = -1;

    for (const auto &[u, _] : adj) {
      if (outdegree[u] - indegree[u] == 1) {
        start_vertex = u;
        break;
      }
    }
    if (start_vertex == -1)
      start_vertex = pairs[0][0];

    std::vector<std::vector<int>> ans{};
    std::function<void(int)> dfs = [&adj, &dfs, &ans](int u) {
      auto &next = adj[u];
      while (!next.empty()) {
        int v = next.back();
        next.pop_back();
        dfs(v);
        ans.push_back({u, v});
      }
    };

    dfs(start_vertex);

    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};