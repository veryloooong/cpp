#include <cstdint>
#include <deque>
#include <iterator>
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

public:
};

class ProductOfNumbers {
private:
  std::vector<int> previous;

public:
  ProductOfNumbers() : previous({1}) {}

  void add(int num) {
    if (num == 0)
      previous = {1};
    else {
      previous.push_back(previous.back() * num);
    }
  }

  int getProduct(int k) {
    const int n = previous.size();
    if (k >= n)
      return 0;
    else
      return previous.back() / previous[n - k - 1];
  }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */