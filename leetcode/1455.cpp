#include <cstdint>
#include <string>
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

  std::vector<std::string> split(std::string s, std::string delim) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delim)) != std::string::npos) {
      token = s.substr(0, pos);
      tokens.push_back(token);
      s.erase(0, pos + delim.length());
    }
    tokens.push_back(s);

    return tokens;
  }

public:
  int isPrefixOfWord(std::string sentence, std::string searchWord) {
    std::vector<std::string> words = split(sentence, " ");

    for (int i = 0, n = words.size(); i < n; i++) {
      if (words.at(i).starts_with(searchWord))
        return i + 1;
    }

    return -1;
  }
};