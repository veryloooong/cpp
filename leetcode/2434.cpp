#include <algorithm>
#include <array>
#include <cstdint>
#include <stack>
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
  string robotWithString(string s) {
    stack<char> stk;
    array<int, 26> cnt;
    string ans;

    for (const char c : s) cnt[c - 'a']++;

    for (const char c : s) {
      stk.push(c);
      cnt[c - 'a']--;
      char smallest = 'a';

      if (auto it = find_if(cnt.begin(), cnt.end(), [](int x) {return x > 0;}); it != cnt.end()) 
        smallest += distance(cnt.begin(), it);
      
      while (!stk.empty() && stk.top() <= smallest) {ans += stk.top(); stk.pop();}
    }

    while (!stk.empty()) {ans += stk.top(); stk.pop();}

    return ans;
  }
};
