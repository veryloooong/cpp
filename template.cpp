#include <cstdint>
#include <fstream>
#include <iostream>

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

constexpr i64 MOD = 1e9 + 7; // NOLINT

const char *inf = "input.txt";
const char *outf = "output.txt";

int main() {
#ifndef ONLINE_JUDGE
  ifstream in(inf);
  ofstream out(outf);

  if (in.good()) {
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
  }
#endif

  int x, y;
  cin >> x >> y;
  cout << x + y;

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */