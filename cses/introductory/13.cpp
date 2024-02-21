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
  vector<int> arr(n + 1);

  for (int j = n; j > 0; --j)
    cout << (arr[j] & 1);
  cout << "\n";

  for (int i = 1; i < (1 << n); ++i) {
    int p = ffs(i);
    arr[p]++;
    for (int j = n; j > 0; --j)
      cout << (arr[j] & 1);
    cout << "\n";
  }
}