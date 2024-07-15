#include <cctype>
#include <iostream>
#include <map>
#include <numeric>
#include <string>

using namespace std;

class Solution {
private:
  string make_elem(string &s, int &i) {
    int start_idx = i++;
    while (i < s.length() && islower(s[i]))
      i++;
    return s.substr(start_idx, i - start_idx);
  }

  int make_count(string &s, int &i) {
    int start_idx = i;
    while (i < s.length() && isdigit(s[i]))
      i++;
    auto numstr = s.substr(start_idx, i - start_idx);
    return numstr.empty() ? 1 : stoi(numstr);
  }

  map<string, int> make_elem_count(string &s, int &i) {
    int len = s.length();
    map<string, int> elems{};

    while (i < len) {
      if (s[i] == '(') {
        map<string, int> inner_elem_count = make_elem_count(s, ++i);
        for (auto &elem_count : inner_elem_count) {
          string elem = elem_count.first;
          int count = elem_count.second;

          elems[elem] += count;
        }
      } else if (s[i] == ')') {
        int group_count = make_count(s, ++i);

        for (auto &&[_, count] : elems) {
          count *= group_count;
        }

        return elems;
      } else {
        string elem = make_elem(s, i);
        int count = make_count(s, i);
        elems[elem] += count;
      }
    }

    return elems;
  }

public:
  string countOfAtoms(string formula) {
    int len = formula.length();
    int i = 0;

    map<string, int> elems = make_elem_count(formula, i);

    auto make_str = [&](string a, pair<string, int> b) {
      string result = std::move(a) + b.first;

      if (b.second > 1)
        result += std::to_string(b.second);

      return result;
    };

    return accumulate(elems.begin(), elems.end(), string(), make_str);
  }
};

int main() {
  Solution s = Solution();
  string formula = "Mg(OH)2";
  string res = s.countOfAtoms(formula);

  cout << res << endl;
}