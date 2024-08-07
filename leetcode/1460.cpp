#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool canBeEqual(vector<int> &target, vector<int> &arr) {
    unordered_map<int, int> seen{};
    for (const int &x : target)
      seen[x]++;

    for (const int &y : arr)
      seen[y]--;

    for (const auto &p : seen)
      if (p.second != 0)
        return false;

    return true;
  }
};