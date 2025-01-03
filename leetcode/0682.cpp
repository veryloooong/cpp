#include <cstdint>
#include <iterator>
#include <numeric>
#include <stdexcept>
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
  int calPoints(std::vector<std::string> &operations) {
    std::vector<int> records;

    for (const auto &op : operations) {
      try {
        records.push_back(std::stoi(op));
      } catch (const std::invalid_argument &) {
        if (op == "+") {
          int x = *records.rbegin();
          int y = *std::next(records.rbegin());
          records.push_back(x + y);
        } else if (op == "C") {
          records.pop_back();
        } else if (op == "D") {
          int x = records.back();
          records.push_back(x * 2);
        }
      }
    }

    return std::accumulate(records.begin(), records.end(), 0);
  }
};