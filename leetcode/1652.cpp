#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  typedef int32_t i32;
  typedef uint32_t u32;
  typedef int64_t i64;
  typedef uint64_t u64;

public:
  vector<int> decrypt(vector<int> &code, int k) {
    int n = code.size();

    if (k == 0) {
      return vector<int>(n, 0);
    }

    vector<int> ans(n, 0);

    int p = abs(k);
    int current = std::accumulate(code.begin(), code.begin() + p, 0);
    ans[p] = current;
    for (int i = p + 1; i - n < p; i++) {
      current = current + code[(i - 1) % n] - code[(i - 1 - p) % n];
      ans[i % n] = current;
    }

    if (k > 0)
      std::rotate(ans.begin(), ans.begin() + p + 1, ans.end());

    return ans;
  }
};

int main() {
  vector<int> ans{2, 4, 9, 3};

  for (const int x : Solution().decrypt(ans, -2)) {
    cout << x << ' ';
  }

  cout << endl;
}