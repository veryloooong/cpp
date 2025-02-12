#include <algorithm>
#include <cstdint>
#include <functional>
#include <iterator>
#include <map>
#include <set>
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

  int sumDigits(int n) {
    int ans = 0;
    while (n) {
      ans += n % 10;
      n /= 10;
    }

    return ans;
  }

public:
  int maximumSum(std::vector<int> &nums) {
    std::map<int, std::multiset<int, std::greater<int>>, std::greater<int>>
        sums;

    for (int num : nums) {
      sums[sumDigits(num)].insert(num);
    }

    int ans = -1;

    for (const auto &[k, s] : sums) {
      if (s.size() > 1)
        ans = std::max(ans, *s.begin() + *std::next(s.begin()));
    }

    return ans;
  }
};