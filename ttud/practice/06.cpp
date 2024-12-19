#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

constexpr i64 MOD = 1e9 + 7; // NOLINT

const char *inf = "input.txt";
const char *outf = "output.txt";

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << '(' << p.first << ',' << p.second << ')';
  return os;
}

template <typename T> ostream &operator<<(ostream &os, const vector<T> &arr) {
  os << '[';
  for (int i = 0, n = arr.size(); i < n; i++) {
    os << arr[i] << (i < n - 1 ? ", " : "");
  }
  os << ']';

  return os;
}

struct yn_tf : numpunct<char> {
  string do_truename() const { return "YES"; }
  string do_falsename() const { return "NO"; }
};

i64 solve() {
  int n, k;
  cin >> n >> k;
  vector<i64> arr(n);
  for (i64 &x : arr)
    cin >> x;

  int best = 1;
  sort(arr.begin(), arr.end());
  for (int i = 1, l = 0; i < n; i++) {
    if (arr[i] - arr[i - 1] > k)
      l = i;
    best = max(best, i - l + 1);
  }

  return n - best;
}

int main() {
#ifndef ONLINE_JUDGE
  ifstream in(inf);
  ofstream out(outf);

  if (in.good()) {
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
  }
#endif

  cout.imbue(locale(cout.getloc(), new yn_tf));
  cout << boolalpha;

  int t;
  cin >> t;
  while (t--)
    cout << solve() << '\n';

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */