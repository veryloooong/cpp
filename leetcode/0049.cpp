#include <algorithm>
#include <cstdint>
#include <string>
#include <unordered_map>
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
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> hm{};
    for (const string &s : strs) {
      string hms = s;
      std::sort(hms.begin(), hms.end());
      hm[hms].push_back(s);
    }

    vector<vector<string>> ans{};

    for (const auto &[_, v] : hm) {
      ans.push_back(v);
    }

    return ans;
  }
};