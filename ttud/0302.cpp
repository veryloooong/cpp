#include <algorithm >
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

constexpr long long MOD = 1e9 + 7;

long long merge(std::vector<int> &arr, int l, int r, int m) {
  if (r - l == 1) {
    int yes = arr[l] > arr[r];
    if (yes)
      std::swap(arr[l], arr[r]);
    return yes;
  }

  long long cnt = 0;

  auto arr_l_begin = arr.begin() + l;
  auto arr_l_end = arr.begin() + m + 1;
  auto arr_r_begin = arr.begin() + m + 1;
  auto arr_r_end = arr.begin() + r + 1;

  for (int j = m + 1; j <= r; j++) {
    auto it = std::upper_bound(arr_l_begin, arr_l_end, arr[j]);
    long long dist = std::distance(it, arr_l_end);
    if (dist == 0)
      break;
    cnt += dist;
  }

  std::vector<int> merged;
  merged.reserve(r - l + 1);

  auto it_l = arr_l_begin;
  auto it_r = arr_r_begin;

  while (it_l != arr_l_end && it_r != arr_r_end) {
    if (*it_l <= *it_r) {
      merged.push_back(*it_l);
      ++it_l;
    } else {
      merged.push_back(*it_r);
      ++it_r;
    }
  }

  while (it_l != arr_l_end) {
    merged.push_back(*it_l);
    ++it_l;
  }

  while (it_r != arr_r_end) {
    merged.push_back(*it_r);
    ++it_r;
  }

  std::copy(merged.begin(), merged.end(), arr.begin() + l);

  return cnt;
}

long long solve(std::vector<int> &arr, int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;
    return ((solve(arr, l, m) + solve(arr, m + 1, r)) % MOD +
            merge(arr, l, r, m)) %
           MOD;
  } else
    return 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> arr(n);
  for (int i = 0; i < n; i++)
    std::cin >> arr[i];

  std::cout << solve(arr, 0, n - 1) << std::endl;
}