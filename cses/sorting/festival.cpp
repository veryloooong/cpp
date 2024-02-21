#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef vector<pair<ll, ll>> vp;

// constexpr ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  ll a, b;
  cin >> n;
  vp arr{};
  arr.reserve(n);
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    arr.push_back({b, a});
  }

  sort(arr.begin(), arr.end());

  int result = 1;
  ll end = arr[0].first;
  for (int i = 1; i < n; ++i) {
    if (arr[i].second >= end) {
      end = arr[i].first;
      result++;
    }
  }

  cout << result << '\n';

  return 0;
}
