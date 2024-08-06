#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int minSwaps(vector<int> &nums) {
    int numOnes = accumulate(nums.begin(), nums.end(), 0);

    // int minimum = numOnes;

    int currentZeros =
        numOnes - accumulate(nums.begin(), next(nums.begin(), numOnes), 0);

    int minimum = min(currentZeros, numOnes);

    for (int i = 1, n = nums.size(); i < n; i++) {
      int right = nums[(i + numOnes - 1) % n];
      int left = nums[i - 1];
      if (left < right)
        currentZeros--;
      else if (left > right)
        currentZeros++;

      // if (nums[(i + numOnes - 1) % n] == 0)
      //   currentZeros++;
      // else
      //   currentZeros--;

      // if (nums[i - 1] == 0)
      //   currentZeros--;
      // else
      //   currentZeros++;

      minimum = min(minimum, currentZeros);
    }

    return minimum;
  }
};

int main() {
  vector<int> nums = {1, 1, 0, 0, 1};
  Solution s = Solution();
  cout << s.minSwaps(nums) << endl;
}