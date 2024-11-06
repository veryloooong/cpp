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
  int maxNumberOfBalloons(string text) {
    array<int, 5> balon_count{};

    for (const char &c : text) {
      switch (c) {
      case 'b':
        balon_count[0]++;
        break;
      case 'a':
        balon_count[1]++;
        break;
      case 'l':
        balon_count[2]++;
        break;
      case 'o':
        balon_count[3]++;
        break;
      case 'n':
        balon_count[4]++;
        break;
      }
    }

    balon_count[2] /= 2;
    balon_count[3] /= 2;
    return std::ranges::min(balon_count);
  }
};