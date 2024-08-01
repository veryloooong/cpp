#include <vector>
class Solution {
public:
  int countTestedDevices(std::vector<int> &percentages) {
    int ans = 0;
    int previously_tested = 0;

    for (const int &x : percentages)
      if (x > 0 && previously_tested < x) {
        previously_tested++;
        ans++;
      }

    return ans;
  }
};

int main() { return 0; }