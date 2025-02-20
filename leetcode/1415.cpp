#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

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

  void backtrack(size_t n, std::string current,
                 std::vector<std::string> &list) {
    if (current.length() == n) {
      list.push_back(current);
      return;
    }

    for (char next = 'a'; next <= 'c'; next++) {
      if (current.length() > 0 && current.back() == next)
        continue;
      backtrack(n, current + next, list);
    }
  }

public:
  std::string getHappyString(int n, int k) {
    std::vector<std::string> list{};
    backtrack(n, "", list);

    std::sort(list.begin(), list.end());
    return list.size() >= k ? list[k - 1] : std::string();
  }
};

int main() { std::cout << Solution().getHappyString(3, 9) << std::endl; }