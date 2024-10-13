#include <iostream>
#include <stack>
#include <string>

bool is_pair(const char c1, const char c2) {
  return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') ||
         (c1 == '{' && c2 == '}');
}

int main() {
  std::stack<char> st{};
  std::string s{};
  std::cin >> s;

  for (const char c : s) {
    if (c == '(' || c == '[' || c == '{')
      st.push(c);
    else {
      if (st.empty() || !is_pair(st.top(), c)) {
        std::cout << 0 << std::endl;
        return 0;
      }

      st.pop();
    }
  }

  std::cout << st.empty() << std::endl;
  return 0;
}