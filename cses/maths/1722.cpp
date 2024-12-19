#include <chrono>
#include <cstdint>
#include <fstream>
#include <iostream>
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

bool compare_files(const std::string &s1, const std::string &s2) {
  std::ifstream f1(s1, std::ifstream::binary | std::ifstream::ate);
  std::ifstream f2(s2, std::ifstream::binary | std::ifstream::ate);

  if (f1.fail() || f2.fail()) {
    return false; // file problem
  }
  if (f1.tellg() != f2.tellg()) {
    return false; // size mismatch
  }
  // seek back to beginning and use std::equal to compare contents
  f1.seekg(0, std::ifstream::beg);
  f2.seekg(0, std::ifstream::beg);
  return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                    std::istreambuf_iterator<char>(),
                    std::istreambuf_iterator<char>(f2.rdbuf()));
}

struct yn_tf : numpunct<char> {
  string do_truename() const { return "YES"; }
  string do_falsename() const { return "NO"; }
};

i64 what(i64 a, i64 b) {
  return ((a * (b + MOD - a) % MOD) + (a * b % MOD)) % MOD;
}

pair<i64, i64> fib(i64 n) {
  if (n == 0)
    return {0, 1};

  auto [a, b] = fib(n >> 1);
  i64 c = what(a, b);
  i64 d = (what(b, a + b) + MOD - c) % MOD;
  if (n & 1)
    return {d, (c + d) % MOD};
  else
    return {c, d};
}

void solve() {
  i64 n;
  cin >> n;
  cout << fib(n).first;
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

  if (!compare_files(outf, expected))
    cerr << "wrong" << endl;
#endif

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */
