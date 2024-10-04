#include <algorithm>
#include <vector>

class Solution {
public:
  int64_t dividePlayers(std::vector<int> &skill) {
    std::sort(skill.begin(), skill.end());

    bool sameLevel = true;
    int skillLevel = skill.front() + skill.back();
    int64_t sumChemistry = 0;
    for (int i = 0, n = skill.size(); i < n / 2; i++) {
      int j = n - 1 - i;
      if (skill[i] + skill[j] != skillLevel)
        return -1;
      sumChemistry += skill[i] * skill[j];
    }

    return sumChemistry;
  }
};