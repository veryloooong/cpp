#include <iostream>
#include <vector>

using namespace std;

// dp[i] tong day con lon nhat thoa man ket thuc tai a[i]
// 2 th: (vi du xet den so 10, truoc no la 9 va truoc no la 8)
vector<int> a, dp;
int kq = INT_MIN;

int dpf(int k) {
  if (dp[k] != -1)
    return dp[k];
  if (k == 0) {
    dp[0] = a[0];
    return dp[0];
  }
  if (k == 1) {
    dp[1] = a[0] + a[1];
    return dp[1];
  }
  if (k == 2) {
    dp[2] = max(a[0] + a[1], max(a[1] + a[2], a[0] + a[2]));
    return dp[2];
  }

  dp[k] = max(dpf(k - 2) + a[k], a[k] + a[k - 1] + dpf(k - 3));
  return dp[k];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp.assign(n, -1);
  for (int i = 0; i < n; i++) {
    kq = max(kq, dpf(i));
  }
  cout << kq;
  return 0;
}