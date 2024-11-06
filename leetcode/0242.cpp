#include <algorithm>
#include <array>
#include <cstdint>
#include <string>

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
  bool isAnagram(string s, string t) {
    array<int, 26> cnt{};

    for (const char &c : s)
      cnt[c - 'a']++;

    for (const char &c : t) {
      if (--cnt[c - 'a'] < 0)
        return false;
    }

    return all_of(cnt.begin(), cnt.end(), [](const int &i) { return i == 0; });
  }
};