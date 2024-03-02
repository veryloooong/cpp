#include <bits/stdc++.h>

constexpr bool is_power_of_two(int x) { return ((x & -x) == x) && x > 0; }

int main() {
  static_assert(is_power_of_two(4), "womp womp");
  static_assert(!is_power_of_two(0), "damn");
  static_assert(is_power_of_two(1), "oof");
  // static_assert(is_power_of_two(3), "oof!!!!"); // this intentionally fails
  /* static_assert(is_power_of_two(0b10000000000000000000000000000000),
                "lol"); // this is INT32_MIN */
  // static_assert(is_power_of_two(INT32_MAX), "no");
}