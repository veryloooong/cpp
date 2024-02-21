#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  cin >> s;
  int count[26]{}, cc = 0;
  memset(count, 0, 26 * sizeof(int));
  for (char c : s)
    count[c - 'A']++;
  for (int i = 0; i < 26; ++i)
    cc += count[i] % 2;
  if (cc > 1)
    cout << "NO SOLUTION\n";
  else {
    string t{};
    for (int i = 0; i < 26; ++i) {
      if (count[i] % 2 == 0)
        for (int j = 0; j < count[i] / 2; ++j)
          t += (char)('A' + i);
    }
    cout << t;
    for (int i = 0; i < 26; ++i)
      if (count[i] % 2 == 1)
        for (int j = 0; j < count[i]; ++j)
          cout << (char)('A' + i);
    reverse(t.begin(), t.end());
    cout << t << "\n";
  }

  return 0;
}