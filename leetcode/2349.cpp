#include <cstdint>
#include <set>
#include <string>
#include <unordered_map>
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

class NumberContainers {
private:
  std::unordered_map<int, std::set<int>> numbers;
  std::unordered_map<int, int> indexes;

public:
  void change(int index, int number) {
    if (auto it = indexes.find(index); it != indexes.end()) {
      int old = it->second;
      numbers[old].erase(index);
      if (numbers[old].empty())
        numbers.erase(old);
    }
    indexes[index] = number;
    numbers[number].insert(index);
  }

  int find(int number) {
    return numbers.contains(number) ? *numbers[number].begin() : -1;
  }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */