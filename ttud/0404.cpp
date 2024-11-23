#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class MaxSegmentTree {
private:
  int num_elems;
  vector<int> tree;

public:
  MaxSegmentTree(int n) : num_elems(n), tree(vector<int>(4 * n)) {}
  MaxSegmentTree(vector<int> &arr) {
    num_elems = arr.size();
    tree = vector<int>(num_elems * 4);
    build(arr);
  }

  void build(vector<int> &arr, int v, int lbound, int rbound) {
    if (lbound == rbound) {
      tree[v] = arr[lbound];
    } else {
      int m = (lbound + rbound) / 2;
      build(arr, v * 2, lbound, m);
      build(arr, v * 2 + 1, m + 1, rbound);
      tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
    }
  }

  void build(vector<int> &arr) { build(arr, 1, 0, arr.size() - 1); }

  int find_max(int v, int lbound, int rbound, int l, int r) {
    if (l > r)
      return numeric_limits<int>::min();
    if (l == lbound && r == rbound)
      return tree[v];
    int m = (lbound + rbound) / 2;
    return max(find_max(2 * v, lbound, m, l, min(r, m)),
               find_max(2 * v + 1, m + 1, rbound, max(l, m + 1), r));
  }

  int find_max(int l, int r) { return find_max(1, 0, num_elems - 1, l, r); }

  void update(int v, int lbound, int rbound, int pos, int x) {
    if (lbound == rbound) {
      tree[v] = x;
    } else {
      int m = (lbound + rbound) / 2;
      if (pos <= m)
        update(2 * v, lbound, m, pos, x);
      else
        update(2 * v + 1, m + 1, rbound, pos, x);
      tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }
  }

  void update(int pos, int x) { update(1, 0, num_elems - 1, pos, x); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, L1, L2;
  cin >> N >> L1 >> L2;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  MaxSegmentTree st(a);

  vector<int> dp(N, 0);
  dp[0] = a[0];

  int ans = 0;

  for (int i = 1; i < N; i++) {
    dp[i] = a[i];

    if (i - L1 >= 0) {
      dp[i] = max(dp[i], st.find_max(max(0, i - L2), i - L1) + a[i]);
    }

    st.update(i, dp[i]);

    ans = max(ans, dp[i]);
  }

  cout << ans << '\n';
}