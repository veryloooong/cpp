#include <climits>
#include <cstdint>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
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

  std::vector<std::vector<int>> tree;
  std::unordered_map<int, int> bobPath;
  std::vector<bool> visited;

  bool bobSolve(int s, int t) {
    visited[s] = true;
    bobPath[s] = t;

    if (s == 0)
      return true;

    for (const auto v : tree[s]) {
      if (!visited[v]) {
        if (bobSolve(v, t + 1))
          return true;
      }
    }

    bobPath.erase(s);
    return false;
  }

public:
  int mostProfitablePath(std::vector<std::vector<int>> &edges, int bob,
                         std::vector<int> &amount) {
    const int n = amount.size();
    tree.resize(n);
    visited.resize(n);
    for (const auto &edge : edges) {
      tree[edge[0]].push_back(edge[1]);
      tree[edge[1]].push_back(edge[0]);
    }

    bobSolve(bob, 0);

    int ans = INT_MIN;
    visited.assign(n, false);
    std::queue<std::tuple<int, int, int>> q; // node, time, income
    q.push({0, 0, 0});

    while (!q.empty()) {
      auto [node, time, income] = q.front();
      q.pop();

      if (!bobPath.contains(node) || time < bobPath[node]) {
        income += amount[node];
      } else if (time == bobPath[node]) {
        income += (amount[node] / 2);
      }

      if (tree[node].size() == 1 && node != 0) {
        ans = std::max(ans, income);
      }
      for (const int v : tree[node]) {
        if (!visited[v]) {
          q.push({v, time + 1, income});
        }
      }

      visited[node] = true;
    }

    return ans;
  }
};