#include <bits/stdc++.h>
#include <utility>

using namespace std;

typedef long long ll;

class Solution {
private:
  static constexpr ll MOD = 1e9 + 7;
  static bool invalid_cell(int i, int j) {
    return i == 3 && (j == 0 || j == 2);
  }

public:
  static int knight_dialer(int n) {
    typedef pair<int, int> p;
    typedef vector<vector<int>> v2d;

    int ans = 0;
    const array<p, 8> valid_moves = {p(2, 1), p(2, -1), p(-2, 1), p(-2, -1),
                                     p(1, 2), p(1, -2), p(-1, 2), p(-1, -2)};

    v2d dp(4, vector<int>(3, 1));
    dp[3][0] = dp[3][2] = 0;

    for (int k = 1; k < n; ++k) {
      v2d calc(4, vector<int>(3));
      for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
          if (invalid_cell(i, j))
            continue;
          else {
            for (auto &move : valid_moves) {
              int x = i + move.first, y = j + move.second;
              if (x < 0 || y < 0 || x > 3 || y > 2 || invalid_cell(x, y))
                continue;
              calc[i][j] = (calc[i][j] + dp[x][y]) % MOD;
            }
          }
        }
      }

      dp = std::move(calc);
    }

    for (auto &row : dp)
      for (auto cell : row)
        ans = (ans + cell) % MOD;

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
}
