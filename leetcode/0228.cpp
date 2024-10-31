#include <cstdint>
#include <string>
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
  vector<string> summaryRanges(vector<int> &nums) {
    if (nums.empty())
      return {};

    int s = nums[0];

    vector<string> ans{};

    int n = nums.size();
    for (int i = 1; i < n; i++) {
      if (nums[i] > nums[i - 1] + 1) {
        if (s == nums[i - 1])
          ans.push_back(to_string(s));
        else
          ans.push_back(to_string(s) + "->" + to_string(nums[i - 1]));

        s = nums[i];
      }
    }

    if (s == nums[n - 1])
      ans.push_back(to_string(s));
    else
      ans.push_back(to_string(s) + "->" + to_string(nums[n - 1]));

    return ans;
  }
};