#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;

// wtf so uhhhh
constexpr ull MAXN = 2e5;
constexpr ull LEVEL_LOG2 = 20;

// we keep a parent 2d array with `parent_level[i][j]` being parent of i `2**j`
// levels up
int parent_log2[MAXN + 1][LEVEL_LOG2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, q;
  cin >> n >> q;

  for (int i = 2; i <= n; ++i) {
    int b;
    cin >> b;
    parent_log2[i][0] = b;
  }

  for (ull j = 1; j < LEVEL_LOG2; ++j)
    for (int i = 1; i <= n; ++i)
      parent_log2[i][j] = parent_log2[parent_log2[i][j - 1]][j - 1];

  for (int j = 0; j < q; ++j) {
    int x, k;
    cin >> x >> k;
    for (ull i = 0; i < LEVEL_LOG2; ++i)
      if (k & (1 << i))
        x = parent_log2[x][i];

    cout << (x > 0 ? x : -1) << '\n';
  }

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */
