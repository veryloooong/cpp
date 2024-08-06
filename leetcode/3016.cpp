#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int minimumPushes(string word) {
    array<int, 26> frequencies{};
    for (const auto &ch : word) {
      frequencies[ch - 'a']++;
    }

    sort(frequencies.begin(), frequencies.end(), std::greater<>());

    int ans = 0;
    int cnt = 0;
    for (const int &freq : frequencies) {
      ans += freq * (cnt++ / 8 + 1);
    }

    return ans;
  }
};

int main() {
  string word = "abcde";
  Solution sol{};
  cout << sol.minimumPushes(word) << endl;
}