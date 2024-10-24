#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
typedef unordered_set<string> Set;

int main() {
  Set s{};
  string str{};

  do {
    cin >> str;
    s.insert(str);
  } while (str != "*");

  do {
    cin >> str;
    if (str == "find") {
      cin >> str;
      cout << (s.find(str) != s.end()) << endl;
    } else if (str == "insert") {
      cin >> str;
      cout << s.insert(str).second << endl;
    } else if (str == "***")
      break;
  } while (true);
}