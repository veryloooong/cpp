#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
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

  i64 hours(std::vector<int> &piles, int m) {
    return std::accumulate(
        piles.begin(), piles.end(), 0LL,
        [m](i64 acc, int x) { return acc + (x - 1) / m + 1; });
  }

public:
  int minEatingSpeed(std::vector<int> &piles, int h) {
    i64 lhs = 1, rhs = *std::ranges::max_element(piles);

    while (lhs < rhs) {
      int m = lhs + (rhs - lhs) / 2;
      if (hours(piles, m) <= h)
        rhs = m;
      else
        lhs = m + 1;
    }

    return lhs;
  }
};

int main() {
  std::vector<int> piles = {3, 6, 7, 11};
  std::cout << Solution().minEatingSpeed(piles, 8) << std::endl;
}