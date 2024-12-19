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

struct Meeting {
  int s, f, w;

  Meeting(int s, int f, int w) : s(s), f(f), w(w) {}
};

int binary_find(const vector<Meeting> &m, int start, int idx) {
  int n = m.size();
  int low = 0, high = idx - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (m[mid].f < start) {
      if (mid == n - 1 || m[mid + 1].f >= start) {
        return mid;
      }
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

void solve() {
  int n;
  cin >> n;
  vector<Meeting> m;
  for (int i = 0; i < n; i++) {
    int s, f, w;
    cin >> s >> f >> w;
    m.push_back({s, f, w});
  }
  sort(m.begin(), m.end(),
       [](Meeting a, Meeting b) { return a.f == b.f ? a.s < b.s : a.f < b.f; });

  vector<int> dp(n + 1);
  dp[0] = m[0].w;

  for (int rhs = 1, i = 0; rhs <= n; i = rhs++) {
    int bin = binary_find(m, m[i].s, i);
    dp[rhs] = max(dp[rhs - 1], m[i].w + (bin != -1 ? dp[bin + 1] : 0));
  }

  cout << dp.back();
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
