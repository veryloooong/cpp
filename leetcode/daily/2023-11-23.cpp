#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<bool> check_arithmetic_subarrays(vector<int> &nums, vector<int> &l,
                                        vector<int> &r) {
  vector<bool> results{};
  vector<int> buf{};
  for (size_t i = 0; i < l.size(); ++i) {
    int li = l[i], ri = r[i];
    buf = {nums.begin() + li, nums.begin() + ri + 1};
    sort(buf.begin(), buf.end());
    int diff = buf[1] - buf[0];
    bool res = true;
    for (size_t j = 0; j < buf.size() - 1; ++j) {
      if (buf[j + 1] - buf[j] != diff) {
        res = false;
        break;
      }
    }
    results.push_back(res);
  }

  return results;
}

int main() {
  vector<int> nums = {4, 6, 5, 9, 3, 7};
  vector<int> l = {0, 0, 2};
  vector<int> r = {2, 3, 5};

  vector<bool> results = check_arithmetic_subarrays(nums, l, r);

  for (auto x : results) {
    cout << x << " ";
  }

  cout << endl;
}