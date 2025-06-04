#include <algorithm>
#include <cstdint>
#include <iostream>
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

  string last_substring(string s) {
    size_t best = 0, cand = 1, len = 0, n = s.length();
    while (cand + len < n) {
      if (s[best + len] == s[cand + len]) {
        len++;
      } else if (s[best + len] > s[cand + len]) {
        cand = cand + len + 1;
        len = 0;
      } else {
        best = max(best + len + 1, cand);
        cand = best + 1;
        len = 0;
      }
    }
    return s.substr(best);
  }

public:
  string answerString(string word, int numFriends) {
    if (numFriends == 1) return word;
    
    const size_t strlen = word.length() - numFriends + 1;
    string s = last_substring(word);

    return s.substr(0, min(s.length(), strlen));
  }
};

int main() {
  string word = "aann";
  int numFriends = 2;
  cout << Solution().answerString(word, numFriends) << endl;
}
