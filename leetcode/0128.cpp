#include <cstdint>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class DSU {
private:
  unordered_map<int, int> parent;
  unordered_map<int, int> sz;

public:
  void add(int x) {
    if (!parent.contains(x)) {
      parent[x] = x;
      sz[x] = 1;
    }
  }

  unordered_map<int, int> &sizes() { return sz; }
  const unordered_map<int, int> &sizes() const { return sz; }

  int find(int x) { return (x == parent[x] ? x : parent[x] = find(parent[x])); }

  bool contains(int x) { return parent.contains(x); }

  void combine(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      if (sz[x] < sz[y])
        std::swap(x, y);
      parent[y] = x;
      sz[x] += sz[y];
    }
  }
};

class Solution {
private:
  typedef int32_t i32;
  typedef uint32_t u32;
  typedef int64_t i64;
  typedef uint64_t u64;

public:
  int longestConsecutive(vector<int> &nums) {
    DSU dsu{};
    for (int &x : nums) {
      dsu.add(x);
      if (dsu.contains(x - 1))
        dsu.combine(x, x - 1);
      if (dsu.contains(x + 1))
        dsu.combine(x, x + 1);
    }

    int ans = 0;

    for (const auto &kv : dsu.sizes()) {
      ans = max(ans, kv.second);
    }

    return ans;
  }
};