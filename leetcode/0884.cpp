#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<std::string> uncommonFromSentences(std::string s1,
                                                 std::string s2) {
    std::unordered_map<std::string, int> hm{};
    std::istringstream iss(s1 + " " + s2);
    std::string word;

    while (iss >> word)
      hm[word]++;

    std::vector<std::string> results;
    for (const auto &[w, c] : hm)
      if (c == 1)
        results.push_back(w);

    return results;
  }
};