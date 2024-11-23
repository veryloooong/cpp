#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <string>

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
  int takeCharacters(string s, int k) {
    array<int, 3> freq{};
    // unordered_map<char, int> freq{};
    for (const char &c : s)
      freq[c - 'a']++;

    if (freq[0] < k || freq[1] < k || freq[2] < k)
      return -1;

    int n = s.size(), ans = n + 1;

    for (int lhs = 0, rhs = 0; rhs < n; rhs++) {
      freq[s[rhs] - 'a']--;
      while (freq[s[rhs] - 'a'] < k)
        freq[s[lhs++] - 'a']++;
      ans = min(ans, lhs + n - rhs - 1);
    }

    return ans;
  }
};

int main() {
  string s{"aabaaaacaabc"};
  int k = 2;

  cout << Solution().takeCharacters(s, k) << endl;
}