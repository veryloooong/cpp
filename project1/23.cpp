#include <iostream>
#include <queue>
#include <string>

int main() {
  std::string s{};
  std::queue<int> q{};

  while (true) {
    std::cin >> s;

    if (s == "PUSH") {
      int x;
      std::cin >> x;
      q.push(x);
    } else if (s == "POP") {
      if (q.empty())
        std::cout << "NULL\n";
      else {
        std::cout << q.front() << '\n';
        q.pop();
      }
    } else if (s == "#")
      break;
  }
}