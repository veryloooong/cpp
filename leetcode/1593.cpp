#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
  void backtrack(const string &s, unordered_set<string> &seen, size_t idx,
                 size_t &ans) {
    if (idx == s.length()) {
      ans = max(ans, seen.size());
      return;
    }

    for (size_t len = 1; idx + len <= s.length(); len++) {
      string sub = s.substr(idx, len);
      if (!seen.contains(sub)) {
        seen.insert(sub);
        backtrack(s, seen, idx + len, ans);
        seen.erase(sub);
      }
    }
  }

public:
  int maxUniqueSplit(string s) {
    size_t ans = 0;
    unordered_set<string> seen{};
    backtrack(s, seen, 0, ans);
    return ans;
  }
};