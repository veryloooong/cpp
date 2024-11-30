#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Treasure {
  int x, y, c;

  Treasure(int x, int y, int c) : x(x), y(y), c(c) {}
};

int main() {
  int n;
  cin >> n;

  vector<Treasure> t;

  for (int i = 0; i < n; i++) {
    int x, y, c;
    cin >> x >> y >> c;

    t.push_back({x, y, c});
  }

  sort(t.begin(), t.end(), [](Treasure &a, Treasure &b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
  });

  vector<long long> dp(n);
  for (int i = 0; i < n; i++)
    dp[i] = t[i].c;

  for (int j = 1; j < n; j++) {
    for (int i = 0; i < j; i++) {
      if (t[i].x <= t[j].x && t[i].y <= t[j].y) {
        dp[j] = max(dp[j], dp[i] + t[j].c);
      }
    }
  }

  cout << *max_element(dp.begin(), dp.end()) << endl;
}