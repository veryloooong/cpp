#include <algorithm>
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
  vector<string> arr{};

  sort(s.begin(), s.end());

  do {
    arr.push_back(s);
  } while (next_permutation(s.begin(), s.end()));

  cout << arr.size() << "\n";
  for (auto str : arr)
    cout << str << "\n";
}