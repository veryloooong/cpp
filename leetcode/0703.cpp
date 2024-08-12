#include <queue>
#include <vector>

class KthLargest {
private:
  std::priority_queue<int, std::vector<int>, std::greater<>> ord;
  int k;

public:
  KthLargest(int k, std::vector<int> &nums) : k(k), ord() {
    for (const auto x : nums) {
      ord.push(x);
      if (ord.size() > k)
        ord.pop();
    }
  }

  int add(int val) {
    ord.push(val);
    if (ord.size() > k)
      ord.pop();
    return ord.top();
  }
};