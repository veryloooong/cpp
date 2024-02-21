#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr ll MOD = 1e9 + 7;

vector<int> get_sum_absolute_differences(vector<int> &nums) {
  vector<int> results{};

  int n = nums.size();

  int res = 0;

  for (int i = 1; i < n; ++i)
    res += abs(nums[0] - nums[i]);
  results.push_back(res);

  for (int i = 1; i < n; ++i) {
    int diff = nums[i] - nums[i - 1];
    res = res - (n - i) * diff + i * diff;
    results.push_back(res);
  }

  return results;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> nums = {1, 4, 6, 8, 10};
  vector<int> results = get_sum_absolute_differences(nums);

  for (auto x : results)
    cout << x << " ";
  cout << endl;
}