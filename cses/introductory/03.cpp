#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int res = 1;
  int cur = 1;
  for (size_t i = 1; i < s.length(); i++) {
    if (s[i] == s[i - 1])
      cur++;
    else
      cur = 1;
    res = max(res, cur);
  }

  cout << res;

  return 0;
}