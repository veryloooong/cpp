#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int countSeniors(vector<string> &details) {
    int ans = 0;

    for (const auto &str : details) {
      int age = stoi(str.substr(11, 2));
      ans += age > 60;
    }

    return ans;
  }
};

int main() { return 0; }