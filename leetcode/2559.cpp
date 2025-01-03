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
  std::vector<int> vowelStrings(std::vector<std::string> &words,
                                std::vector<std::vector<int>> &queries) {
    const int n = words.size();
    const int q = queries.size();
    std::vector<int> ans(q);
    const std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
    std::vector<int> prefix(n + 1);

    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + (vowels.contains(words[i].front()) &&
                                   vowels.contains(words[i].back()));
    }

    for (int i = 0; i < q; i++) {
      ans[i] = prefix[queries[i][1] + 1] - prefix[queries[i][0]];
    }

    return ans;
  }
};