#include <vector>

class Solution {
public:
  bool lemonadeChange(std::vector<int> &bills) {
    int five$ = 0;
    int ten$ = 0;

    for (const int &pay : bills) {
      if (pay == 5)
        five$++;
      else if (pay == 10) {
        if (five$ > 0) {
          five$--;
          ten$++;
        } else
          return false;
      } else if (pay == 20) {
        if (ten$ > 0 && five$ > 0) {
          ten$--;
          five$--;
        } else if (five$ >= 3)
          five$ -= 3;
        else
          return false;
      }
    }

    return true;
  }
};