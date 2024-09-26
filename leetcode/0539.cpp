#include <algorithm>
#include <iterator>
#include <limits>
#include <string>
#include <vector>

class Solution {
private:
  int parseTimeString(const std::string &s) {
    return std::stoi(s.substr(0, 2)) * 60 +
           std::stoi(s.substr(3, std::string::npos));
  }

public:
  int findMinDifference(std::vector<std::string> &timePoints) {
    int minTimeDiff = std::numeric_limits<int>::max();

    std::vector<int> times{};
    times.reserve(timePoints.size());

    std::transform(timePoints.begin(), timePoints.end(),
                   std::back_inserter(times),
                   [&](const std::string &s) { return parseTimeString(s); });

    std::sort(times.begin(), times.end());

    for (int i = 0; i < timePoints.size() - 1; i++) {
      minTimeDiff = std::min(minTimeDiff, times[i + 1] - times[i]);
    }

    minTimeDiff = std::min(minTimeDiff, 1440 + times.front() - times.back());

    return minTimeDiff;
  }
};
