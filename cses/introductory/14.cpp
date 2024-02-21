#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr ll MOD = 1e9 + 7;

void tower(int n, int a, int b, int c) {
  if (n <= 0)
    return;
  tower(n - 1, a, c, b);
  cout << a << " " << b << '\n';
  tower(n - 1, c, b, a);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  cout << (1 << n) - 1 << '\n';
  tower(n, 1, 3, 2);
}