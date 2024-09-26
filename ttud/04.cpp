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

  int lhs = 0, rhs = 0;
  int current = 0;
  int maxSize = 0;

  while (rhs < n) {
    current += arr[rhs];
    maxSize = max(maxSize, rhs - lhs + 1);
    while (current > m) {
      current -= arr[lhs++];
    }
    rhs++;
  }

  cout << maxSize - 1 << endl;
}