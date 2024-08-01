#include <vector>

using namespace std;

class Solution {
public:
  int minHeightShelves(vector<vector<int>> &books, int shelfWidth) {
    vector<int> dp(books.size() + 1, 2000000);
    dp[0] = 0;

    for (int i = 1; i <= books.size(); i++) {
      int currentWidth = 0;
      int currentHeight = 0;
      for (int j = i; j > 0; j--) {
        int width = books[j - 1][0];
        int height = books[j - 1][1];

        currentWidth += width;
        if (currentWidth > shelfWidth)
          break;

        currentHeight = max(currentHeight, height);
        dp[i] = min(dp[i], dp[j - 1] + currentHeight);
      }
    }

    return dp[books.size()];
  }
};

int main() { return 0; }