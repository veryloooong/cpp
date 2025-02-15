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
  int minOperations(std::vector<int> &nums, int k) {
    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> numbers;
    for (int n : nums)
      numbers.push(n);

    int cnt = 0;

    while (numbers.top() < k) {
      i64 x = numbers.top();
      numbers.pop();
      i64 y = numbers.top();
      numbers.pop();
      numbers.push(x * 2 + y);
      cnt++;
    }

    return cnt;
  }
};