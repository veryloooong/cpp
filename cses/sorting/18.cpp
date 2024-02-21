#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  set<int> count;
  int n;
  cin >> n;
  int a;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    count.insert(a);
  }
  cout << count.size() << endl;
}