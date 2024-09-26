#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  int n, k;
  ifstream inp("../input.txt");
  inp >> n >> k;
  // cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    // cin >> arr[i];
    inp >> arr[i];

  long long currentSum = accumulate(arr.begin(), next(arr.begin() + k), 0LL);
  int cnt = (currentSum % 2 == 0);

  for (int i = k; i < n; i++) {
    currentSum = currentSum - arr[i - k] + arr[i];
    cnt += (currentSum % 2 == 0);
  }

  cout << cnt << endl;
}
