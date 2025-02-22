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

struct yn_tf : numpunct<char> {
  string do_truename() const { return "YES"; }
  string do_falsename() const { return "NO"; }
};

int solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;

  const auto p = minmax_element(arr.begin(), arr.end());
  return *p.second - *p.first;
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