#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
private:
  // impl of `n >> k` in base b
  static int shift_right(int n, int k, int b) {
    while (k--)
      n /= b;
    return n;
  }

public:
  static int distributeCookies(vector<int> &cookies, int k) {
    int ans = INT_MAX;
    int n = cookies.size();
    vector<int> children(k);

    if (n == k)
      return ranges::max(cookies);

    for (int i = 0; i < pow(k, n); ++i) {
      for (int j = 0; j < n; ++j)
        children[Solution::shift_right(i, j, k) % k] += cookies[j];
      ans = min(ans, ranges::max(children));
      children = vector<int>(k, 0);
    }

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> cookies = {61887, 37245, 29144, 54577};
  assert(Solution::distributeCookies(cookies, 3) == 66389);
}
