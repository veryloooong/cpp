#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 1e9;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long ans = -INF;
  long long current = 0;
  long long even_sum = 0;
  long long odd_sum = INF;
  bool has_odd = false;

  for (int i = 0; i < n; i++) {
    current += a[i];
    if (abs(current) % 2 == 0) {
      ans = max(ans, current - even_sum);
      even_sum = min(even_sum, current);
    } else {
      if (has_odd) {
        ans = max(ans, current - odd_sum);
      }

      has_odd = true;
      odd_sum = min(odd_sum, current);
    }
  }

  if (ans == -INF) {
    cout << "NOT_FOUND" << endl;
  } else {
    cout << ans << endl;
  }
}