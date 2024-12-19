#include <cmath>
#include <cstdint>
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

public:
  long long pickGifts(std::vector<int> &gifts, int k) {
    std::priority_queue<int> heap(gifts.begin(), gifts.end());
    for (int i = 0; i < k; i++) {
      int x = heap.top();
      heap.pop();
      heap.push(std::sqrt(x));
    }
    i64 ans = 0;
    while (!heap.empty()) {
      ans += heap.top();
      heap.pop();
    }
    return ans;
  }
};