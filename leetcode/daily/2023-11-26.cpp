#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr ll MOD = 1e9 + 7;

// the solution
class Solution {
public:
  static int largest_submatrix(vector<vector<int>> &nums) {
    int ans = 0, n = nums.size(), m = nums[0].size();
    vector<vector<int>> rows(n);
    for (int i = 0; i < n; ++i)
      rows[i].resize(m);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (nums[i][j])
          rows[i][j] = (i > 0 ? rows[i - 1][j] : 0) + 1;
      }
    }

    for (int i = 0; i < n; ++i) {
      sort(rows[i].begin(), rows[i].end());
      for (int j = 0; j < m; ++j) {
        ans = max(ans, rows[i][j] * (m - j));
      }
    }

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<vector<int>> matrix = {{0, 0, 1}, {1, 1, 1}, {1, 0, 1}};
  int ans = Solution::largest_submatrix(matrix);
  cout << ans << endl;

  matrix = {{1}};
  ans = Solution::largest_submatrix(matrix);
  cout << ans << endl;
}