#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minOperations(vector<string> &logs) {
    int currentDepth = 0;

    for (const auto &l : logs) {
      if (l == "../") {
        if (currentDepth > 0)
          currentDepth--;
      } else if (l == "./") {
        continue;
      } else {
        currentDepth++;
      }
    }

    return currentDepth;
  }
};

int main() { return 0; }