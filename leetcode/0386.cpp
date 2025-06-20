#include <cstdint>
#include <string>
#include <vector>

using namespace std;

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
  vector<int> lexicalOrder(int n) {
    vector<int> ans;
    ans.reserve(n);

    int current = 1;
    while ((int)ans.size() < n) {
      ans.push_back(current);
      if (current * 10 <= n) current *= 10;
      else {
        while (current % 10 == 9 || current >= n) current /= 10;
        current++;
      }
    }
    
    return ans;
  }
};
