#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());
    int lhs = 0;
    int rhs = people.size() - 1;

    int ans = 0;
    while (lhs < rhs) {
      if (people[lhs] + people[rhs] <= limit) lhs++;
      rhs--;
      ans++;
    }

    return ans;
  }
};
