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
  bool canConstruct(string ransomNote, string magazine) {
    // unordered_map<char, int> cnt{};
    array<int, 26> cnt{};

    for (const char &c : magazine)
      cnt[c - 'a']++;

    for (const char &c : ransomNote) {
      if (--cnt[c - 'a'] < 0)
        return false;
    }

    return true;
  }
};