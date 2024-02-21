#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr ll MOD = 1e9 + 7;

int max_product_difference(vector<int> &nums) {
  int n = nums.size();
  sort(nums.begin(), nums.end());

  return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> nums = {5, 6, 2, 7, 4};
  cout << max_product_difference(nums) << endl;
}
