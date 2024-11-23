#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> d(n + 1, 1e6);
  d[0] = -1e6;

  for (int i = 0; i < n; i++) {
    int j = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
    if (d[j - 1] < a[i] && a[i] < d[j]) {
      d[j] = a[i];
    }
  }

  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (d[i] < 1e6) {
      ans = i;
    }
  }

  cout << ans << endl;
}