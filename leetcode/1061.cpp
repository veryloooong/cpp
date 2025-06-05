#include <cstdint>
#include <numeric>
#include <string>
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
  vector<int> parent;

public:
  DSU(): parent(26) {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int a) {
    return a == parent[a] ? a : (parent[a] = find(parent[a]));
  }

  void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a > b) swap(a, b);
    parent[b] = a;
  }
};

class Solution {
private:
  typedef int32_t i32;
  typedef uint32_t u32;
  typedef int64_t i64;
  typedef uint64_t u64;

public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    DSU dsu{};
    for (size_t i = 0, n = s1.length(); i < n; i++) {
      dsu.join(s1[i] - 'a', s2[i] - 'a');
    }
    string ans;
    for (const char c : baseStr) {
      ans += 'a' + dsu.find(c - 'a');
    }
    return ans;
  }
};
