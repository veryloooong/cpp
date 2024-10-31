#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

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
public:
  int minimumMountainRemovals(vector<int> &nums) {
    vector<int> lis_l = lis(nums);
    vector<int> reversed_nums(nums.rbegin(), nums.rend());
    vector<int> lis_r = lis(reversed_nums);
    lis_r = vector<int>(lis_r.rbegin(), lis_r.rend());

    int ans = 0;

    for (int i = 0, n = nums.size(); i < n; i++) {
      if (lis_l[i] > 1 && lis_r[i] > 1)
        ans = max(ans, lis_l[i] + lis_r[i] - 1);
    }

    return nums.size() - ans;
  }

private:
  vector<int> lis(vector<int> &nums) {
    vector<int> length_to_min_largest{};
    vector<int> dp{};

    for (const int num : nums) {
      if (length_to_min_largest.empty() || num > length_to_min_largest.back()) {
        length_to_min_largest.push_back(num);
      } else {
        int idx = std::lower_bound(length_to_min_largest.begin(),
                                   length_to_min_largest.end(), num) -
                  length_to_min_largest.begin();
        length_to_min_largest[idx] = num;
      }
      dp.push_back(length_to_min_largest.size());
    }

    return dp;
  }
};