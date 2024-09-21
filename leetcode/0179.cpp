#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string largestNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), [](int a, int b) {
      return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    });

    string ans =
        std::accumulate(nums.begin(), nums.end(), ""s, [](string a, int b) {
          return std::move(a) + std::to_string(b);
        });

    return ans[0] == '0' ? "0"s : ans;
  }
};
