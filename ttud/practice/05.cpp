#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <utility>
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

bool solve() {
  int n, k;
  cin >> n >> k;
  map<i64, i64> dist_hp;
  vector<i64> hps(n);
  for (i64 &hp : hps)
    cin >> hp;
  for (int i = 0; i < n; i++) {
    i64 x;
    cin >> x;
    dist_hp[abs(x)] += hps[i];
  }

  i64 cur = 0;
  for (const auto &[dist, hp] : dist_hp) {
    cur += hp;
    if (dist * k < cur)
      return false;
  }

  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  ifstream in(inf);
  ofstream out(outf);

  if (in.good()) {
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
  }
#endif // ONLINE_JUDGE

  cout.imbue(locale(cout.getloc(), new yn_tf));
  cout << boolalpha;

  int t;
  cin >> t;
  while (t--)
    cout << solve() << '\n';

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */