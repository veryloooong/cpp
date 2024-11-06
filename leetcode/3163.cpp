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
  string compressedString(string word) {
    string res{};
    int cnt = 1;
    char current = word[0];

    for (size_t i = 1; i < word.size(); i++) {
      if (word[i] == current) {
        if (cnt == 9) {
          res += to_string(cnt);
          res += current;
          current = word[i];
          cnt = 1;
        } else
          cnt++;
      } else {
        res += to_string(cnt);
        res += current;
        current = word[i];
        cnt = 1;
      }
    }

    res += to_string(cnt);
    res += current;

    return res;
  }
};