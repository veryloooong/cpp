#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int cnt = 0;
  sort(arr.begin(), arr.end());

  int lhs = 0, rhs = n - 1;
  while (lhs < rhs) {
    int s = arr[lhs] + arr[rhs];
    if (s > m)
      rhs--;
    else if (s < m)
      lhs++;
    else {
      cnt++;
      rhs--;
      lhs++;
    }
  }

  cout << cnt << endl;
}