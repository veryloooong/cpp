#include <string>
#include <string_view>

class Solution {
public:
  std::string shortestPalindrome(std::string s) {
    const std::string t{s.crbegin(), s.crend()};
    const std::string_view sv_s(s);
    const std::string_view sv_t(t);

    for (int i = 0; i < s.length(); i++) {
      if (sv_s.substr(0, s.length() - i) == sv_t.substr(i)) {
        return t.substr(0, i) + s;
      }
    }

    return t + s;
  }
};