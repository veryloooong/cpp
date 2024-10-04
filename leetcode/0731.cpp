#include <algorithm>
#include <set>
#include <utility>

class MyCalendarTwo {
  std::set<std::pair<int, int>> single_books_timeline{};
  std::set<std::pair<int, int>> double_books_timeline{};

public:
  MyCalendarTwo() : single_books_timeline(), double_books_timeline() {}

  bool book(int start, int end) {
    for (const auto &[s, e] : double_books_timeline)
      if (std::max(start, s) < std::min(end, e))
        return false;

    for (const auto &[s, e] : single_books_timeline) {
      const int overlap_start = std::max(start, s);
      const int overlap_end = std::min(end, e);
      if (overlap_start < overlap_end) {
        double_books_timeline.insert({overlap_start, overlap_end});
      }
    }

    single_books_timeline.insert({start, end});
    return true;
  }
};