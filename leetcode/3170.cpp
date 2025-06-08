#include <cstdint>
#include <functional>
#include <queue>
#include <string>
#include <utility>
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
  string clearStars(string s) {
    using pair_t = pair<char, int>;
    priority_queue<pair_t, vector<pair_t>, greater<>> pq; // character, location
    string ans = s;
    
    for (int i = 0, n = s.length(); i < n; i++) {
      if (s[i] != '*') pq.push({s[i], -i});
      else {
        const auto [_, pos] = pq.top(); pq.pop();
        ans[-pos] = '*';
      }
    }

    std::erase(ans, '*');

    return ans;
  }
};
