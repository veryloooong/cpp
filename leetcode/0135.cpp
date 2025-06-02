#include <cstdint>
#include <numeric>
#include <string>
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
  int candy(vector<int> &ratings) {
    const int n = ratings.size();
    vector<int> arr(n, 1);

    for (int i = 1; i < n; i++)
      if (ratings[i - 1] < ratings[i])
        arr[i] = arr[i - 1] + 1;

    for (int i = n - 2; i >= 0; i--)
      if (ratings[i] > ratings[i + 1] && arr[i] <= arr[i + 1])
        arr[i] = arr[i + 1] + 1;

    return accumulate(arr.begin(), arr.end(), 0);
  }
};