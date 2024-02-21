#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef multiset<int, greater<int>> ordset;

const int MAXN = 200005;

int main() {
  int n;
  cin >> n;
  ll ans = 0;

  array<int, MAXN> arr{};

  int p;
  for (int i = 0; i < n; ++i) {
    cin >> p;
    arr[p]++;
  }

  ordset freq;

  for (auto x : arr) {
    if (x > 0)
      freq.insert(x);
  }

  int count = 1;
  for (auto x : freq) {
    ans += x * count;
    count++;
  }

  cout << ans << endl;
}
