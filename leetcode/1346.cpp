#include <cstdint>
#include <string>
#include <unordered_set>
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
  bool checkIfExist(std::vector<int> &arr) {
    std::unordered_set<int> seen{};
    for (const int &x : arr) {
      if (seen.contains(2 * x))
        return true;
      if (x % 2 == 0 && seen.contains(x / 2))
        return true;
      seen.insert(x);
    }

    return false;
  }
};