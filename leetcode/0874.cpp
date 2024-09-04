#include <iostream>
#include <set>
#include <utility>
#include <vector>

class Solution {
public:
  int robotSim(std::vector<int> &commands,
               std::vector<std::vector<int>> &obstacles) {
    const std::vector<coord_t> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    coord_t pos{0, 0};
    int currentDirection = 0;
    int maxDist = 0;

    std::set<coord_t> obs{};
    for (const auto &ob : obstacles) {
      obs.insert({ob[0], ob[1]});
    }

    for (const int &command : commands) {
      if (command == -2)
        currentDirection = (currentDirection + 3) % 4;
      else if (command == -1)
        currentDirection = (currentDirection + 1) % 4;
      else {
        const auto &dir = DIRECTIONS[currentDirection];
        for (int i = 0; i < command; i++) {
          const coord_t nextPos = moveRobot(pos, dir);
          if (obs.find(nextPos) != obs.end())
            break;
          pos = moveRobot(pos, dir);
          maxDist = std::max(maxDist,
                             pos.first * pos.first + pos.second * pos.second);
        }
      }
    }

    return maxDist;
  }

private:
  using coord_t = std::pair<int, int>;

  coord_t moveRobot(coord_t current, coord_t dir) {
    return {
        current.first + dir.first,
        current.second + dir.second,
    };
  }
};

int main() {
  std::vector<int> commands = {4, -1, 3};
  std::vector<std::vector<int>> obstacles = {};

  std::cout << Solution().robotSim(commands, obstacles) << std::endl;
}