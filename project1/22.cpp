#include <iostream>
#include <stack>
#include <string>

int main() {
  std::stack<int> st{};
  std::string s{};
  while (true) {
    std::cin >> s;
    if (s == "PUSH") {
      int x;
      std::cin >> x;
      st.push(x);
    } else if (s == "POP") {
      if (st.empty())
        std::cout << "NULL\n";
      else {
        std::cout << st.top() << '\n';
        st.pop();
      }
    } else if (s == "#")
      break;
  }
}