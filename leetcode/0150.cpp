#include <cstdint>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
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

  typedef std::function<int(int, int)> operator_t;

  const std::unordered_map<std::string, operator_t> operations{
      std::make_pair("+", static_cast<operator_t>(std::plus<>())),
      std::make_pair("-", static_cast<operator_t>(std::minus<>())),
      std::make_pair("*", static_cast<operator_t>(std::multiplies<>())),
      std::make_pair("/", static_cast<operator_t>(std::divides<>())),
  };

public:
  int evalRPN(std::vector<std::string> &tokens) {
    std::vector<int> values;

    for (const auto &token : tokens) {
      if (!operations.contains(token))
        values.push_back(std::stoi(token));
      else {
        int x = values.back();
        values.pop_back();
        int y = values.back();
        values.pop_back();
        values.push_back(operations.at(token)(y, x));
      }
    }

    return values.back();
  }
};

int main() {
  std::vector<std::string> tokens{"4", "13", "5", "/", "+"};

  std::cout << Solution().evalRPN(tokens);
}