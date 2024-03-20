#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;

ull expo(ull base, ull exponent, ull mod = 1e9 + 7) {
  ull result = 1;

  while (exponent > 0) {
    if (exponent & 1)
      result = (result * base) % mod;
    base = (base * base) % mod;
    exponent >>= 1;
  }

  return result;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> procs(n);
  for (int i = 0; i < n; ++i)
    cin >> procs[i];

  int t;
  cin >> t;
  vector<int> tasks(t);
  for (int i = 0; i < t; ++i)
    cin >> tasks[i];

  sort(procs.begin(), procs.end());
  sort(tasks.begin(), tasks.end(), greater<int>());

  int ans = INT_MIN;

  for (int i = 0; i < n; ++i) {
    ans = max(ans, procs[i] + tasks[4 * i]);
  }

  cout << ans << '\n';

  return 0;
}