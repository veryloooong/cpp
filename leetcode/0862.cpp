#include <cstdint>
#include <deque>
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

public:
  int shortestSubarray(vector<int> &nums, int k) {
    int n = nums.size();
    vector<i64> prefix(n + 1);
    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + nums[i];
    }

    deque<int> dq;
    int ans = n + 1;
    for (int i = 0; i <= n; i++) {
      while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
        ans = min(ans, i - dq.front());
        dq.pop_front();
      }
      while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
        dq.pop_back();
      }
      dq.push_back(i);
    }

    return ans == n + 1 ? -1 : ans;
  }
};