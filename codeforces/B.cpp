#include <cstdint>
#include <iostream>

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

u32 or_range(u32 a, u32 b) {
  if (a == b)
    return a;
  u32 ans = 0;
  u32 rev = 0;

  while (b) {
    ans *= 2;
    if (a % 2 || a != b)
      ans++;
    a >>= 1;
    b >>= 1;
  }

  while (ans) {
    rev <<= 1;
    rev += ans & 1;
    ans >>= 1;
  }

  return rev;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    u32 n, m;
    cin >> n >> m;
    u32 l = n - m > 0 ? n - m : 0;
    u32 r = n + m;
    cout << or_range(l, r) << "\n";
  }

  cout.flush();

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */
