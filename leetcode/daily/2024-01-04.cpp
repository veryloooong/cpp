#include <bits/stdc++.h>

using namespace std;

int min_operations(vector<int> &nums) {
  unordered_map<int, int> hm{};
  for (auto x : nums) {
    hm[x] += 1;
  }
  int ans = 0;
  for (auto p : hm) {
    if (p.second == 1) {
      return -1;
    }

    ans += (p.second - 1) / 3 + 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> nums = {2, 2, 3, 3, 3, 2};
  cout << min_operations(nums) << endl;
}
