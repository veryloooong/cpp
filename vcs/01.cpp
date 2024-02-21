#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unordered_set<int> hs;

int cycle(vector<int> &arr, vector<int> &c) {
  hs has;

  c.push_back(1);
  has.insert(1);

  int cur = arr[0];
  while (cur != 1) {
    c.push_back(cur);
    has.insert(cur);
    cur = arr[cur - 1];
    if (has.find(cur) != has.end()) {
      return cur;
    }
  }

  return 1;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  int p;

  for (int i = 0; i < n; ++i) {
    cin >> p;
    arr.push_back(p);
  }

  ll secs;
  cin >> secs;
  vector<int> c;

  int has_cycle = cycle(arr, c);

  int c_idx = c.size();

  for (int i = 0; i < c.size(); ++i) {
    if (has_cycle == c[i]) {
      c_idx = i;
      break;
    }
  }

  // cout << has_cycle << "\n";

  // for (auto x : c)
  //   cout << x << ' ';

  // cout << endl << c_idx << endl;

  if (c_idx == 0) {
    int idx = secs % c.size();
    cout << c[idx] << endl;
  } else {
    secs = secs - c_idx;
    int start = c_idx;
    int rg = c.size() - start;
    cout << c[c_idx + secs % rg] << endl;
  }
}