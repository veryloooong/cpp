#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> fullBloomFlowers(vector<vector<int>> &flowers,
                               vector<int> &people) {
    vector<int> starts{};
    vector<int> ends{};

    for (auto &x : flowers) {
      starts.push_back(x[0]);
      ends.push_back(x[1] + 1);
    }

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    vector<int> ans;

    const auto it1 = starts.cbegin();
    const auto it2 = ends.cbegin();
    const auto it3 = starts.cend();
    const auto it4 = ends.cend();

    for (auto x : people) {
      ans.push_back(distance(it1, upper_bound(it1, it3, x)) -
                    distance(it2, upper_bound(it2, it4, x)));
    }

    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> flowers{{1, 6}, {3, 7}, {9, 12}, {4, 13}};
  vector<int> people = {2, 3, 7, 11};

  auto ans = sol.fullBloomFlowers(flowers, people);
  for (auto x : ans)
    cout << x << " ";

  return 0;
}
