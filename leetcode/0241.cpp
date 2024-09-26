#include <string>
#include <vector>

class Solution {
public:
  std::vector<int> diffWaysToCompute(std::string expression) {
    std::vector<int> ans{};

    for (int i = 0; i < expression.size(); i++) {
      char operation = expression[i];
      if (operation == '+' || operation == '-' || operation == '*') {
        std::string lhs = expression.substr(0, i);
        std::string rhs = expression.substr(i + 1);
        std::vector<int> lefts = diffWaysToCompute(lhs);
        std::vector<int> rights = diffWaysToCompute(rhs);
        for (const int &l : lefts) {
          for (const int &r : rights) {
            switch (operation) {
            case '+':
              ans.push_back(l + r);
              break;
            case '-':
              ans.push_back(l - r);
              break;
            case '*':
              ans.push_back(l * r);
              break;
            }
          }
        }
      }
    }

    if (ans.size() == 0)
      ans.push_back(std::stoi(expression));

    return ans;
  }
};