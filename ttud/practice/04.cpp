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

bool solve() {
  int n;
  cin >> n;
  vector<bool> is_odd(n);
  vector<int> odd, even;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    if (x & 1) {
      odd.emplace_back(x);
      is_odd[i] = true;
    } else
      even.emplace_back(x);
  }

  sort(odd.begin(), odd.end());
  sort(even.begin(), even.end());
  vector<int> arr;
  for (int i = 0, l1 = 0, l2 = 0; i < n; i++) {
    if (is_odd[i])
      arr.push_back(odd[l1++]);
    else
      arr.push_back(even[l2++]);
  }

  return is_sorted(arr.begin(), arr.end());
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