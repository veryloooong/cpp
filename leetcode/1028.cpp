#include <cstdint>
#include <string>
#include <tuple>
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

  TreeNode *traverse(std::string &traversal, int depth, int &i) {
    const int n = traversal.length();
    int dashes = 0;

    while (i + dashes < n && traversal[i + dashes] == '-')
      dashes++;
    if (dashes != depth)
      return nullptr;

    i += depth;
    size_t len = 0;
    int val = std::stoi(traversal.substr(i), &len);
    i += len;
    return new TreeNode(val, traverse(traversal, depth + 1, i),
                        traverse(traversal, depth + 1, i));
  }

public:
  TreeNode *recoverFromPreorder(std::string traversal) {
    int i = 0;
    return traverse(traversal, 0, i);
  }
};