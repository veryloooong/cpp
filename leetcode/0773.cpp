#include <array>
#include <cassert>
#include <cstdint>
#include <queue>
#include <unordered_set>
#include <utility>
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

  const std::vector<std::vector<int>> SOLUTION{{1, 2, 3}, {4, 5, 0}};

  int hash_board_state(const std::vector<std::vector<int>> &arr) const {
    assert(arr.size() * arr[0].size() == 6);

    int hash_value = 0;
    for (int i = 0; i < 6; i++)
      hash_value += (arr[i / 3][i % 3] << (3 * i));
    return hash_value;
  }

  inline int find_pos_0(const int &state) {
    int pos_0 = 0;
    while (pos_0 < 6 && (state & (7 << (3 * pos_0))))
      pos_0++;

    return pos_0;
  }

  const std::array<std::pair<int, int>, 4> dirs = {
      std::make_pair(0, 1), std::make_pair(0, -1), std::make_pair(1, 0),
      std::make_pair(-1, 0)};

public:
  int slidingPuzzle(std::vector<std::vector<int>> &board) {
    // bfs
    const int SOLUTION_HASH = hash_board_state(SOLUTION);
    std::queue<std::pair<int, int>> states{};
    std::unordered_set<int> visited{};

    states.push({hash_board_state(board), 0});
    while (!states.empty()) {
      const auto [state, steps] = states.front();
      states.pop();

      if (visited.contains(state))
        continue;

      visited.insert(state);
      if (state == SOLUTION_HASH) {
        return steps;
      }

      int pos_0 = find_pos_0(state);
      int x = pos_0 / 3;
      int y = pos_0 % 3;

      for (const auto &[dx, dy] : dirs) {
        const int nx = x + dx;
        const int ny = y + dy;

        if (nx < 0 || nx >= 2 || ny < 0 || ny >= 3)
          continue;

        int new_state = state;
        int tile = (state >> (3 * (nx * 3 + ny))) & 7;

        new_state =
            new_state ^ (tile << (3 * pos_0)) ^ (tile << (3 * (nx * 3 + ny)));

        states.push({new_state, steps + 1});
      }
    }

    return -1;
  }
};