#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, a;
  cin >> n;
  multiset<int> towers{};
  for (int i = 0; i < n; ++i) {
    cin >> a;
    set<int>::iterator lol = towers.upper_bound(a);
    if (lol != towers.end())
      towers.erase(lol);
    towers.insert(a);
  }

  cout << towers.size() << endl;
}
