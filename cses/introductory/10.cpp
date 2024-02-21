#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  int ans = 0;

  int i = 5;
  while (n / i >= 1) {
    ans += n / i;
    i *= 5;
  }

  cout << ans << endl;
}