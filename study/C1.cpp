#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int binarySearch(vector<pair<int, int>> &meetings, int index) {
  int low = 0, high = index - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (meetings[mid].second <= meetings[index].first) {
      if (meetings[mid + 1].second <= meetings[index].first)
        low = mid + 1;
      else
        return mid;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<tuple<int, int, int>> meetings(n);
  for (int i = 0; i < n; i++) {
    int s, f, w;
    cin >> s >> f >> w;
    meetings[i] = {s, f, w};
  }
  sort(meetings.begin(), meetings.end(),
       [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
         return get<1>(a) < get<1>(b);
       });
  vector<pair<int, int>> intervals(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    intervals[i] = {get<0>(meetings[i]), get<1>(meetings[i])};
    weights[i] = get<2>(meetings[i]);
  }
  vector<int> dp(n, 0);
  dp[0] = weights[0];
  for (int i = 1; i < n; i++) {
    int latest = binarySearch(intervals, i);
    int include = weights[i] + (latest != -1 ? dp[latest] : 0);
    int exclude = dp[i - 1];
    dp[i] = max(include, exclude);
  }
  cout << dp[n - 1] << endl;
  return 0;
}