#include <array>
#include <cstdint>
#include <functional>
#include <string>
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

class Solution {
private:
  typedef int32_t i32;
  typedef uint32_t u32;
  typedef int64_t i64;
  typedef uint64_t u64;

  static int max(int a, int b) { return std::max(a, b); }
  static int min(int a, int b) { return std::min(a, b); }

public:
  int maxDifference(string s) {
    array<int, 26> arr;
    for (const char c : s)
      arr[c - 'a']++;
    array<int, 2> cnt = {INT_MAX, 0};
    array<function<int(int, int)>, 2> fns = {min, max};
    for (const int x : arr) if (x) {
      const int i = x % 2;
      cnt[i] = fns[i](x, cnt[i]);
    }

    return cnt[1] - cnt[0];
  }
};
