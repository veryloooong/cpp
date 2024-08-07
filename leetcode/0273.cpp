#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
// #include <unordered_map>
#include <map>
#include <vector>

using namespace std;

class Solution {
private:
  map<int, string, std::greater<>> digitToString{{1, "One"},
                                                 {2, "Two"},
                                                 {3, "Three"},
                                                 {4, "Four"},
                                                 {5, "Five"},
                                                 {6, "Six"},
                                                 {7, "Seven"},
                                                 {8, "Eight"},
                                                 {9, "Nine"},
                                                 {10, "Ten"},
                                                 {11, "Eleven"},
                                                 {12, "Twelve"},
                                                 {13, "Thirteen"},
                                                 {14, "Fourteen"},
                                                 {15, "Fifteen"},
                                                 {16, "Sixteen"},
                                                 {17, "Seventeen"},
                                                 {18, "Eighteen"},
                                                 {19, "Nineteen"},
                                                 {20, "Twenty"},
                                                 {30, "Thirty"},
                                                 {40, "Forty"},
                                                 {50, "Fifty"},
                                                 {60, "Sixty"},
                                                 {70, "Seventy"},
                                                 {80, "Eighty"},
                                                 {90, "Ninety"},
                                                 {100, "Hundred"},
                                                 {1'000, "Thousand"},
                                                 {1'000'000, "Million"},
                                                 {1'000'000'000, "Billion"},
                                                 {0, ""}};

  vector<int> splitNumber(int num) {
    vector<int> ans{};

    int i = 0;

    while (num > 0) {
      ans.push_back(num % 1000 * (int)pow(1000, i++));
      num /= 1000;
    }

    if (ans.empty())
      ans.push_back(0);

    reverse(ans.begin(), ans.end());

    return ans;
  }

  string pieceToString(int num) {
    assert(num < 1000);

    string ans =
        digitToString[num / 100] + (num >= 100 ? " Hundred" : "") +
        ((num / 100 == 0 || num % 100 == 0) ? "" : " ") +
        ((num % 100) / 10 <= 1
             ? (digitToString[num % 100])
             : (digitToString[(num % 100) / 10 * 10] +
                (num % 10 == 0 ? "" : (" " + digitToString[num % 10]))));

    return ans;
  }

public:
  string numberToWords(int num) {
    if (num == 0)
      return "Zero";

    const vector<int> chunks = splitNumber(num);

    string ans{};

    for (const int &chunk : chunks) {
      if (chunk == 0)
        continue;

      auto place = std::upper_bound(
          digitToString.begin(), digitToString.end(), chunk,
          [](int a, pair<int, string> b) { return a >= b.first; });

      int piece = chunk / place->first;
      string placeModifier = place->second;

      if (place->first < 1000) {
        piece = chunk;
        placeModifier = "";
      }

      ans += pieceToString(piece) + " " + placeModifier + " ";
    }

    return ans.substr(0, ans.find_last_not_of(" ") + 1);
  }
};

int main() {
  int num;
  cin >> num;
  Solution s = Solution();
  cout << s.numberToWords(num) << endl;
}
