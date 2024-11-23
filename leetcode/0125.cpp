#include <cctype>
#include <cstdint>
#include <iostream>
#include <iterator>
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

#include <ranges>

class Solution {
private:
  typedef int32_t i32;
  typedef uint32_t u32;
  typedef int64_t i64;
  typedef uint64_t u64;

public:
  bool isPalindrome(std::string s) {
    std::string filtered;
    std::ranges::copy(s | std::ranges::views::filter([](char c) {
                        return std::isalnum(c);
                      }) | std::ranges::views::transform([](char c) {
                        return std::tolower(c);
                      }),
                      std::back_inserter(filtered));

    std::cout << filtered << std::endl;

    for (int lhs = 0, rhs = filtered.length() - 1; lhs < rhs; lhs++, rhs--)
      if (filtered[lhs] != filtered[rhs])
        return false;

    return true;
  }
};