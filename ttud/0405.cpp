#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct treasure {
  int x, y, c;

  treasure(int x, int y, int c) : x(x), y(y), c(c) {}
};

int main() {
  int n;
  cin >> n;
  vector<treasure> t{};
  for (int i = 0; i < n; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    t.push_back({x, y, c});
  }

  sort(t.begin(), t.end(), [](treasure &a, treasure &b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
  });

  vector<long long> dp(n);
  for (int i = 0; i < n; i++)
    dp[i] = t[i].c;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (t[j].x <= t[i].x && t[j].y <= t[i].y)
        dp[i] = max(dp[i], dp[j] + t[i].c);
    }
  }

  cout << *max_element(dp.begin(), dp.end());
}