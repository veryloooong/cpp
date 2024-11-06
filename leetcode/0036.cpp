#include <bitset>
#include <cstdint>
#include <optional>
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
  bool isValidSudoku(vector<vector<char>> &board) {
    bool check = true;
    for (int i = 0; i < 9; i++) {
      check = check && isValidSudokuRow(board, i) &&
              isValidSudokuCol(board, i) && isValidSudokuSquare(board, i);
    }

    return check;
  }

private:
  optional<int> getIndex(char &c) {
    int i = c - '1';
    if (i < 0 || i >= 9)
      return std::nullopt;
    return i;
  }

  bool isValidSudokuRow(vector<vector<char>> &board, int row) {
    if (row < 0 || row >= 9)
      return false;

    bitset<9> check{};

    for (int i = 0; i < 9; i++) {
      if (auto opt = getIndex(board[row][i]); opt.has_value()) {
        int idx = opt.value();
        if (check.test(idx))
          return false;
        check.set(idx);
      }
    }

    return true;
  }

  bool isValidSudokuCol(vector<vector<char>> &board, int col) {
    if (col < 0 || col >= 9)
      return false;

    bitset<9> check{};

    for (int i = 0; i < 9; i++) {
      if (auto opt = getIndex(board[i][col]); opt.has_value()) {
        int idx = opt.value();
        if (check.test(idx))
          return false;
        check.set(idx);
      }
    }

    return true;
  }

  bool isValidSudokuSquare(vector<vector<char>> &board, int square) {
    if (square < 0 || square >= 9)
      return false;

    bitset<9> check{};

    int row = square / 3 * 3;
    int col = square % 3 * 3;

    for (int i = 0; i < 9; i++) {
      if (auto opt = getIndex(board[row + i / 3][col + i % 3]);
          opt.has_value()) {
        int idx = opt.value();
        if (check.test(idx))
          return false;
        check.set(idx);
      }
    }

    return true;
  }
};