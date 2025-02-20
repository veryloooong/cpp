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
  std::string smallestNumber(std::string pattern) {
    std::string mask = "I" + pattern;
    std::vector<int> cnt_d(mask.length());
    std::vector<int> ans(mask.length());

    int cnt = 0;
    for (int i = cnt_d.size() - 1; i >= 0; i--) {
      cnt_d[i] = cnt;
      if (mask[i] == 'I')
        cnt = 0;
      else
        cnt++;
    }

    std::vector<bool> used(10);
    int min = 1;
    for (int i = 0, n = ans.size(); i < n; i++) {
      int num;
      if (mask[i] == 'I') {
        num = min + cnt_d[i];
      } else {
        num = ans[i - 1] - 1;
      }
      ans[i] = num;
      used[num] = true;
      if (used[min]) {
        while (used[++min])
          ;
      }
    }

    std::string s{};
    for (int x : ans)
      s += std::to_string(x);
    return s;
  }
};