#include <array>
#include <iostream>
#include <ostream>
#include <queue>
#include <tuple>
#include <vector>

int main() {
  using state_t = std::tuple<int, int, int>;

  int a, b, c;
  std::cin >> a >> b >> c;

  std::queue<state_t> states{};
  std::vector<std::vector<bool>> seen(a + 1, std::vector<bool>(b + 1, false));

  states.push({a, b, 0});

  while (!states.empty()) {
    auto [x, y, steps] = states.front();
    states.pop();

    if (x == c || y == c) {
      std::cout << steps << std::endl;
      return 0;
    }

    if (seen[x][y])
      continue;
    seen[x][y] = true;
    std::array<state_t, 6> moves{
        std::make_tuple(0, y, steps + 1),
        std::make_tuple(a, y, steps + 1),
        std::make_tuple(x, 0, steps + 1),
        std::make_tuple(x, b, steps + 1),
        std::make_tuple(x + std::min(y, a - x), y - std::min(y, a - x),
                        steps + 1),
        std::make_tuple(x - std::min(x, b - y), y + std::min(x, b - y),
                        steps + 1),
    };

    for (const auto &move : moves) {
      states.push(move);
    }
  }

  std::cout << -1 << std::endl;
  return 0;
}