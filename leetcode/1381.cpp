#include <algorithm>
#include <vector>

class CustomStack {
private:
  std::vector<int> stack;
  std::size_t size;

public:
  CustomStack(int maxSize) : size(maxSize) { stack.reserve(size); }

  void push(int x) {
    if (stack.size() < size) {
      stack.push_back(x);
    }
  }

  int pop() {
    if (stack.empty()) {
      return -1;
    } else {
      int x = stack.back();
      stack.pop_back();
      return x;
    }
  }

  void increment(int k, int val) {
    std::for_each_n(stack.begin(),
                    std::min(static_cast<size_t>(k), stack.size()),
                    [&](auto &x) { x += val; });
  }
};