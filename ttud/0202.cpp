#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int height, width, n;
vector<pair<int, int>> rects{};
vector<vector<bool>> matrix{};

bool check(int x, int y, bool rotate, int k) {
  auto [h, w] = rects[k];
  if (rotate) {
    swap(h, w);
  }
  if (x + h > height || y + w > width) {
    return false;
  }
  for (int i = x; i < x + h; i++) {
    for (int j = y; j < y + w; j++) {
      if (matrix[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void place(int x, int y, bool rotate, int k, bool mark) {
  auto [h, w] = rects[k];
  if (rotate) {
    swap(h, w);
  }

  for (int i = x; i < x + h; i++) {
    for (int j = y; j < y + w; j++) {
      matrix[i][j] = mark;
    }
  }
}

int backtrack(int k) {
  for (bool rotate : {false, true}) {
    auto [h, w] = rects[k];
    if (rotate)
      swap(h, w);

    for (int x = 0; x <= height - h; x++) {
      for (int y = 0; y <= width - w; y++) {
        if (check(x, y, rotate, k)) {
          place(x, y, rotate, k, true);
          if (k == n - 1)
            return 1;
          else if (backtrack(k + 1))
            return 1;
          place(x, y, rotate, k, false);
        }
      }
    }
  }

  return 0;
}

int main() {
  cin >> height >> width >> n;
  matrix.resize(height, vector<bool>(width));

  for (int i = 0; i < n; i++) {
    int h, w;
    cin >> h >> w;
    rects.push_back({h, w});
  }

  cout << backtrack(0) << endl;
}