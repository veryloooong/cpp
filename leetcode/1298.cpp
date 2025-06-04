#include <cstdint>
#include <queue>
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
  int maxCandies(vector<int> &status, vector<int> &candies,
                 vector<vector<int>> &keys, vector<vector<int>> &containedBoxes,
                 vector<int> &initialBoxes) {
    int ans = 0;
    queue<int> q;
    vector<bool> closed(status.size());

    auto push_boxes = [&status, &q, &closed](const vector<int> &boxes) {
      for (const int box : boxes) {
        if (status[box])
          q.push(box);
        else
          closed[box] = true;
      }
    };

    push_boxes(initialBoxes);

    while (!q.empty()) {
      const int current_box_index = q.front();
      q.pop();

      ans += candies[current_box_index];

      for (const int key : keys[current_box_index]) {
        if (!status[key] && closed[key]) {
          q.push(key);
        }
        status[key] = true;
      }

      push_boxes(containedBoxes[current_box_index]);
    }

    return ans;
  }
};
