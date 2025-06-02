#include <cstdint>
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
  std::vector<std::vector<int>>
  mergeArrays(std::vector<std::vector<int>> &nums1,
              std::vector<std::vector<int>> &nums2) {
    int i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size();
    std::vector<std::vector<int>> ans;
    while (i < n1 && j < n2) {
      auto &v1 = nums1[i];
      auto &v2 = nums2[j];
      if (v1[0] == v2[0]) {
        ans.push_back({v1[0], v1[1] + v2[1]});
        i++;
        j++;
      } else if (v1[0] > v2[0]) {
        ans.push_back(v2);
        j++;
      } else {
        ans.push_back(v1);
        i++;
      }
    }
    while (i < n1) {
      ans.push_back(nums1[i++]);
    }
    while (j < n2) {
      ans.push_back(nums2[j++]);
    }
    return ans;
  }
};