#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <unordered_map>

int hms_to_seconds(const std::string &time) {
  int h, m, s;
  sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s);
  return h * 3600 + m * 60 + s;
}

int main() {
  size_t submission_count = 0;
  size_t error_count = 0;
  // std::unordered_map<std::string, int> user_points;
  std::unordered_map<std::string, std::unordered_map<std::string, int>>
      user_points;
  std::unordered_map<std::string, int> user_errors;

  std::map<int, int> submission_times;

  while (true) {
    std::string user_id, problem_id, time, status;
    std::cin >> user_id;
    if (user_id == "#")
      break;
    std::cin >> problem_id >> time >> status;

    int seconds = hms_to_seconds(time);
    int points;
    std::cin >> points;

    submission_count++;

    if (status == "ERR") {
      error_count++;
      user_errors[user_id]++;
    } else {
      user_points[user_id][problem_id] =
          std::max(user_points[user_id][problem_id], points);
    }

    submission_times[seconds]++;
  }

  std::unordered_map<std::string, int> user_total_points{};
  for (const auto &user : user_points) {
    int total_points = 0;
    for (const auto &problem : user.second) {
      total_points += problem.second;
    }
    user_total_points[user.first] = total_points;
  }

  for (auto it = std::next(submission_times.begin());
       it != submission_times.end(); it++) {
    it->second += std::prev(it)->second;
  }

  std::string cmd{};

  while (cmd != "#") {
    std::cin >> cmd;
    if (cmd == "?total_number_submissions") {
      std::cout << submission_count << '\n';
    } else if (cmd == "?number_error_submision") {
      std::cout << error_count << '\n';
    } else if (cmd == "?number_error_submision_of_user") {
      std::string user_id;
      std::cin >> user_id;

      std::cout << user_errors[user_id] << '\n';
    } else if (cmd == "?total_point_of_user") {
      std::string user_id;
      std::cin >> user_id;

      std::cout << user_total_points[user_id] << '\n';
    } else if (cmd == "?number_submission_period") {
      std::string start, end;
      std::cin >> start >> end;

      int start_seconds = hms_to_seconds(start);
      int end_seconds = hms_to_seconds(end);

      auto start_it = submission_times.lower_bound(start_seconds);
      auto end_it = std::prev(submission_times.upper_bound(end_seconds));

      int count = 0;
      if (start_it != submission_times.begin()) {
        count = std::prev(start_it)->second;
      }

      if (start_it == submission_times.end() ||
          end_it == submission_times.end()) {
        std::cout << 0 << '\n';
        continue;
      }

      count = end_it->second - count;

      std::cout << count << '\n';
    }
  }
}