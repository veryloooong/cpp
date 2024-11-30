#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int q;
  cin >> q;

  int ans = 0;

  for (int t = 0, tm = 1 << n; t < tm; ++t) {
    int s = 0;
    for (int i = 0; i < n; i++) {
      if (t & (1 << i))
        s += arr[i];
    }
    ans += (s >= q);
  }

  cout << ans << endl;
}