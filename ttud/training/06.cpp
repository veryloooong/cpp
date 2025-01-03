#include <algorithm>
#include <chrono>
#include <climits>
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
  struct Block {
    int l, w, h;
  };

  int L, W, H, N;
  cin >> L >> W >> H >> N;
  vector<Block> a(N);
  for (int i = 0; i < N; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    a[i] = {x, y, z};
  }

  vector<vector<vector<i64>>> dp(
      L + 1, vector<vector<i64>>(W + 1, vector<i64>(H + 1, INT_MAX)));

  for (int l = 1; l <= L; l++) {
    for (int w = 1; w <= W; w++) {
      for (int h = 1; h <= H; h++) {
        for (const auto &block : a) {
          if ((l == block.l && w == block.w && h == block.h) ||
              (l == block.w && w == block.h && h == block.l) ||
              (l == block.h && w == block.l && h == block.w) ||
              (l == block.l && w == block.h && h == block.w) ||
              (l == block.w && w == block.l && h == block.h) ||
              (l == block.h && w == block.w && h == block.l)) {
            dp[l][w][h] = 0;
          }
        }
      }
    }
  }

  for (int l = 1; l <= L; l++) {
    for (int w = 1; w <= W; w++) {
      for (int h = 1; h <= H; h++) {
        if (dp[l][w][h] == INT_MAX) {
          i64 waste = l * w * h;
          for (int c = 1; c < l; c++) {
            waste = min(waste, dp[c][w][h] + dp[l - c][w][h]);
          }
          for (int c = 1; c < w; c++) {
            waste = min(waste, dp[l][c][h] + dp[l][w - c][h]);
          }
          for (int c = 1; c < h; c++) {
            waste = min(waste, dp[l][w][c] + dp[l][w][h - c]);
          }
          dp[l][w][h] = waste;
        }
      }
    }
  }

  cout << dp[L][W][H] << '\n';
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

  int t;
  cin >> t;
  while (t--)
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
