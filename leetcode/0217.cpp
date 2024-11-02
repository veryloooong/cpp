#include <cstdint>
#include <fstream>
#include <iostream>
#include <istream>
#include <unordered_set>
#include <vector>

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

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
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> check{};

    for (const int &c : nums) {
      auto res = check.insert(c).second;

      if (!res)
        return true;
    }

    return false;
  }
};

int main() {
  std::ifstream is("C:\\Users\\Long\\Repos\\cpp\\input.txt");
  if (is.is_open()) {
    vector<int> nums{};
    while (is.good() || !is.eof()) {
      int x;
      is >> x;
      nums.push_back(x);
    }
    cout << (Solution().containsDuplicate(nums) ? "true" : "false") << endl;
  }
}