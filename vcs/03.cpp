#include <array>
#include <iostream>

using namespace std;

const int MAXN = 200005;

int main() {
  int n;
  cin >> n;
  array<int, MAXN> pos{};

  int p;
  for (int i = 1; i <= n; ++i) {
    cin >> p;
    pos[p] = i;
  }

  int idx_1 = pos[1];

  int l, r;
  l = r = idx_1;

  cout << 1;
  for (int k = 2; k < n; ++k) {
    int idx_k = pos[k];
    if (idx_k < l)
      l = idx_k;
    if (idx_k > r)
      r = idx_k;
    cout << (r - l >= k ? 0 : 1);
  }
  cout << 1 << endl;
}