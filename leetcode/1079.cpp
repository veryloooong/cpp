#include <cstdint>
#include <map>
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

  int backtrack(std::map<char, int> &letters) {
    int comps = 0;

    for (auto &[c, v] : letters) {
      if (v > 0) {
        v--;
        comps += 1 + backtrack(letters);
        v++;
      }
    }

    return comps;
  }

public:
  int numTilePossibilities(std::string tiles) {
    std::map<char, int> letters;
    for (char c : tiles)
      letters[c]++;
    return backtrack(letters);
  }
};