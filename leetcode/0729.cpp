#include <iterator>
#include <map>

class MyCalendar {
private:
  std::map<int, int> times{};

public:
  MyCalendar() : times() {}

  bool book(int start, int end) {
    auto time_slot = times.lower_bound(end);

    if (time_slot == times.begin() || std::prev(time_slot)->second <= start) {
      times[start] = end;
      return true;
    }

    return false;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */