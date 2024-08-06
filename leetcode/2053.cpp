#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  string kthDistinct(vector<string> &arr, int k) {
    unordered_map<string, int> appearances{};

    for (const auto &x : arr) {
      appearances[x]++;
    }

    int cnt = 0;
    for (const auto &x : arr) {
      if (appearances[x] == 1) {
        cnt++;
        if (cnt == k)
          return x;
      }
    }

    return string();
  }
};