#include <algorithm>
#include <cstdint>
#include <string>
#include <unordered_set>

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
  int numJewelsInStones(string jewels, string stones) {
    unordered_set<char> check(jewels.begin(), jewels.end());

    return count_if(stones.begin(), stones.end(),
                    [&check](const char &c) { return check.contains(c); });
  }
};