#include <algorithm>
#include <cstdint>
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

class SegmentTree {
private:
  int sz;
  std::vector<int> tree;

  void update(int v, int lb, int rb, int key, int val) {
    if (lb >= rb)
      tree[v] = val;
    else {
      int m = (lb + rb) / 2;
      if (key <= m)
        update(2 * v, lb, m, key, val);
      else
        update(2 * v + 1, m + 1, rb, key, val);
      tree[v] = std::max(tree[2 * v], tree[2 * v + 1]);
    }
  }

  int query(int v, int lb, int rb, int x, int y) {
    if (x > y)
      return 0;
    if (lb == x && rb == y)
      return tree[v];

    int m = (lb + rb) / 2;
    return std::max(query(2 * v, lb, m, x, std::min(y, m)),
                    query(2 * v + 1, m + 1, rb, std::max(x, m + 1), y));
  }

public:
  SegmentTree(int sz) : sz(sz), tree(4 * sz + 4) {}

  void update(int key, int val) { update(1, 1, sz, key, val); }

  int query(int x, int y) { return query(1, 1, sz, x, y); }
};

class Solution {
private:
  typedef int32_t i32;
  typedef uint32_t u32;
  typedef int64_t i64;
  typedef uint64_t u64;

public:
  int lengthOfLIS(std::vector<int> &nums) {
    std::vector<int> sorted(nums);
    std::ranges::sort(sorted);
    std::unordered_map<int, int> compress;
    int at = 0;
    for (int v : sorted) {
      if (!compress.contains(v))
        compress[v] = ++at;
    }
    for (size_t i = 0; i < nums.size(); i++) {
      nums[i] = compress[nums[i]];
    }

    SegmentTree st(nums.size());

    for (int v : nums) {
      int res = 0;
      if (v > 1)
        res = st.query(1, v - 1);
      st.update(v, res + 1);
    }
    return st.query(1, nums.size());
  }
};