#include <algorithm>
#include <iterator>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

class Solution {
private:
  static constexpr int MOD = 1e9 + 7;

  // calculates the count of subarrays with sum not greater than `upperBound`
  pair<int, long> subarrayCount(vector<int> &nums, int upperBound) {
    int n = nums.size();

    int count = 0;
    long allSums = 0;
    int subarraySums = 0;
    int windowSum = 0;

    for (int lhs = 0, rhs = 0; rhs < n; rhs++) {
      windowSum += nums[rhs]; // Put `nums[rhs]` into window
      subarraySums +=
          (rhs - lhs + 1) * nums[rhs]; // All subarrays ending at `rhs` gets
                                       // added to this sum of subarrays

      while (windowSum > upperBound) {
        subarraySums -=
            windowSum; // Remove the previous window from subarray sums
        windowSum -= nums[lhs++]; // Remove from window
      }

      count += rhs - lhs + 1;
      allSums += subarraySums;
    }

    return {count, allSums};
  }

  long subarraySumsOfFirst(vector<int> &nums, int k) {
    int l = *min_element(nums.begin(), nums.end());
    int r = accumulate(nums.begin(), nums.end(), 0);

    while (l < r) {
      int m = l + (r - l) / 2;
      if (subarrayCount(nums, m).first < k)
        l = m + 1;
      else
        r = m;
    }

    const auto countAndSum = subarrayCount(nums, l);

    return countAndSum.second - (countAndSum.first - k) * l;
  }

public:
  int rangeSum(vector<int> &nums, int n, int left, int right) {
    return (subarraySumsOfFirst(nums, right) -
            subarraySumsOfFirst(nums, left--)) %
           MOD;
  }
};

class Solution2 : public Solution {
private:
  static constexpr int MOD = 1e9 + 7;

public:
  int rangeSum(vector<int> &nums, int n, int left, int right) {
    vector<int> subarraySums(n * (n + 1) / 2, 0);
    for (int i = 0, k = 0; i < n; i++) {
      int s = 0;
      // subarraySums[k++] = nums[i];
      for (int j = i; j < n; j++, k++) {
        // subarraySums[k] = subarraySums[k - 1] + nums[j];
        s += nums[j];
        subarraySums[k] = s;
      }
    }
    sort(subarraySums.begin(), subarraySums.end());
    return accumulate(next(subarraySums.begin(), left - 1),
                      next(subarraySums.begin(), right), 0,
                      [](int a, int b) { return (a + b) % MOD; });
  }
};