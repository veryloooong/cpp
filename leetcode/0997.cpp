#include <bits/stdc++.h>

using namespace std;

int find_judge(int n, vector<vector<int>> &trust) {
  vector<int> counts(n + 1);
  for (const auto &p : trust) {
    counts[p[0]]--;
    counts[p[1]]++;
  }
  for (int i = 1; i <= n; ++i)
    if (counts[i] == n - 1)
      return i;

  return -1;
}

int main() {
  int n = 3;
  vector<vector<int>> trust{{1, 3}, {2, 3}};

  assert(find_judge(n, trust) == 3);

  return 0;
}