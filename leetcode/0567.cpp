#include <array>
#include <string>

#include <ranges>
class Solution {
public:
  bool checkInclusion(std::string s1, std::string s2) {
    std::array<int, 26> freqs1{};
    std::array<int, 26> freqs2{};

    for (const char &c : s1)
      freqs1[c - 'a']++;

    for (const char &c : s2 | std::ranges::views::take(s1.size())) {
      freqs2[c - 'a']++;
    }

    if (freqs1 == freqs2)
      return true;

    for (int i = s1.size(); i < s2.size(); i++) {
      freqs2[s2[i] - 'a']++;
      freqs2[s2[i - s1.size()] - 'a']--;
      if (freqs1 == freqs2)
        return true;
    }

    return false;
  }
};