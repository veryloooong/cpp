#include <algorithm>
#include <chrono>
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
const char *expected = "expected.txt";

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

void solve() {
  int n;
  cin >> n;
  struct Treasure {
    int x, y, c;
  };

  vector<Treasure> t;
  for (int i = 0; i < n; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    t.push_back({x, y, c});
  }

  sort(t.begin(), t.end(), [](const Treasure &a, const Treasure &b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
  });

  vector<i64> dp(n);
  for (int i = 0; i < n; i++) {
    dp[i] = t[i].c;
  }
  for (int j = 1; j < n; j++) {
    for (int i = 0; i < j; i++) {
      if (t[i].x <= t[j].x && t[i].y <= t[j].y) {
        dp[j] = max(dp[j], dp[i] + t[j].c);
      }
    }
  }

  cout << *max_element(dp.begin(), dp.end());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

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
  cerr << boolalpha;

#ifndef ONLINE_JUDGE
  auto start = chrono::high_resolution_clock::now();
#endif

  solve();

#ifndef ONLINE_JUDGE
  auto end = chrono::high_resolution_clock::now();
  auto elapsed = end - start;
  cerr << "runtime: "
       << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count()
       << " ms" << endl;
#endif

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */
