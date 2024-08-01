#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumDeletions(string s) {
    vector<int> countSuffixA(s.length());
    vector<int> countPrefixB(s.length());

    for (int i = 1; i < s.length(); i++) {
      countPrefixB[i] = countPrefixB[i - 1] + (s[i - 1] == 'b');
    }

    for (int j = s.length() - 2; j >= 0; j--) {
      countSuffixA[j] = countSuffixA[j + 1] + (s[j + 1] == 'a');
    }

    return inner_product(
        countSuffixA.begin(), countSuffixA.end(), countPrefixB.begin(), 2000000,
        [](int a, int b) { return min(a, b); }, std::plus<>());
  }
};

int main() {
  Solution sol = Solution();
  string s = "aababbab";
  cout << sol.minimumDeletions(s) << endl;
  return 0;
}