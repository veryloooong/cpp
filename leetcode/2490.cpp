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
  bool isCircularSentence(string sentence) {
    if (sentence.length() <= 1)
      return true;

    // size_t start = 0;
    size_t end = sentence.find(" ");

    while (end != string::npos) {
      if (sentence[end - 1] != sentence[end + 1])
        return false;

      // start = end + 1;
      end = sentence.find(" ", ++end);
    }

    return sentence.front() == sentence.back();
  }
};