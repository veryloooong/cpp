#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;

// constexpr ll MOD = 1e9 + 7;
ull pow_10(int x) {
  ull n = 1;
  while (x--)
    n *= 10;
  return n;
}

int solve() {
  ull x;
  cin >> x;
  if (x < 9)
    return x;

  x -= 1;
  int numlen = 1;
  while (9 * pow_10(numlen - 1) * numlen < x) {
    x -= 9 * pow_10(numlen - 1) * numlen;
    numlen++;
  }

  string s = to_string(pow_10(numlen - 1) + x / numlen);
  return s[x % numlen] - '0';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  while (n--)
    cout << solve() << '\n';
}
