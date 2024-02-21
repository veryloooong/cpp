#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    while (a > 0 && b > 0) {
      if (a == b) {
        a -= a / 3 * 3;
        b -= b / 3 * 3;
        if (a < 3)
          break;
      } else {
        int c = abs(a - b);
        if (a > b) {
          a -= 2 * c;
          b -= 1 * c;
        } else {
          a -= 1 * c;
          b -= 2 * c;
        }
      }
    }
    if (a == 0 && b == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}