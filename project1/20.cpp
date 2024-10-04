#include <iostream>
#include <vector>

using namespace std;

bool is_valid(const vector<vector<int>> &board, int row, int col, int num) {
  // Check if `num` is not in the current row
  for (int c = 0; c < 9; ++c) {
    if (board[row][c] == num) {
      return false;
    }
  }

  // Check if `num` is not in the current column
  for (int r = 0; r < 9; ++r) {
    if (board[r][col] == num) {
      return false;
    }
  }

  // Check if `num` is not in the current 3x3 box
  int box_row_start = (row / 3) * 3;
  int box_col_start = (col / 3) * 3;
  for (int r = box_row_start; r < box_row_start + 3; ++r) {
    for (int c = box_col_start; c < box_col_start + 3; ++c) {
      if (board[r][c] == num) {
        return false;
      }
    }
  }

  return true;
}

int count_solutions(vector<vector<int>> &board) {
  int row, col;
  bool empty_found = false;

  // Find the next empty cell
  for (row = 0; row < 9; ++row) {
    for (col = 0; col < 9; ++col) {
      if (board[row][col] == 0) {
        empty_found = true;
        break;
      }
    }
    if (empty_found)
      break;
  }

  if (!empty_found) {
    return 1; // Found a complete solution
  }

  int count = 0;

  // Try numbers 1 to 9
  for (int num = 1; num <= 9; ++num) {
    if (is_valid(board, row, col, num)) {
      board[row][col] = num;           // Place the number
      count += count_solutions(board); // Recur to place next number
      board[row][col] = 0;             // Backtrack
    }
  }

  return count;
}

int main() {
  vector<vector<int>> board(9, vector<int>(9));

  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      cin >> board[i][j];
    }
  }

  int solution_count = count_solutions(board);
  cout << solution_count << endl;

  return 0;
}