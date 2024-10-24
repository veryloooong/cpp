#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

std::vector<int64_t> find_dist_array(std::vector<int64_t> &arr, size_t sz,
                                     int64_t dist) {
  std::vector<int64_t> ans{arr[0]};

  for (size_t i = 1; i < arr.size(); i++) {
    if (arr[i] - ans.back() >= dist)
      ans.push_back(arr[i]);
    if (ans.size() >= sz)
      break;
  }

  return ans;
}

void solve() {
  size_t n, k;
  std::cin >> n >> k;

  std::vector<int64_t> arr(n);
  for (size_t i = 0; i < n; i++)
    std::cin >> arr[i];

  std::sort(arr.begin(), arr.end());

  int64_t dist_low = 0, dist_high = arr.back() - arr.front();

  while (dist_low < dist_high) {
    int64_t mid = (dist_low + dist_high + 1) / 2;

    if (find_dist_array(arr, k, mid).size() == k)
      dist_low = mid;
    else
      dist_high = mid - 1;
  }

  std::cout << dist_low << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--)
    solve();

  std::cout.flush();
}