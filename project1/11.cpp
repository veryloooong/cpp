#include <array>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <tuple>

using namespace std;

using bill_step_t = tuple<int, int, int>;

class Bills {
private:
  const array<bill_step_t, 6> steps_old = {
      make_tuple(0, 50, 1728),
      make_tuple(50, 100, 1786),
      make_tuple(100, 200, 2074),
      make_tuple(200, 300, 2612),
      make_tuple(300, 400, 2919),
      make_tuple(400, numeric_limits<int>::max(), 3015),
  };

  const array<bill_step_t, 5> steps_new = {
      make_tuple(0, 100, 1728),
      make_tuple(100, 200, 2074),
      make_tuple(200, 400, 2612),
      make_tuple(400, 700, 3111),
      make_tuple(700, numeric_limits<int>::max(), 3457),
  };

  template <size_t N>
  int calculate_bills(int kwh, array<bill_step_t, N> steps) {
    int total_bill = 0;

    for (const auto &[start, end, price] : steps) {
      if (kwh <= end) {
        total_bill += (kwh - start) * price;
        break;
      } else {
        total_bill += (end - start) * price;
      }
    }

    return total_bill;
  }

public:
  int calculate_old_bills(int kwh) { return calculate_bills(kwh, steps_old); }
  int calculate_new_bills(int kwh) { return calculate_bills(kwh, steps_new); }
  int calculate_diff(int kwh) {
    return calculate_new_bills(kwh) - calculate_old_bills(kwh);
  }
  double calculate_diff_with_tax(int kwh) {
    double diff = calculate_diff(kwh);
    return diff * 11. / 10;
  }
};

int main() {
  int kwh;
  cin >> kwh;
  cout << setprecision(2) << fixed << Bills().calculate_diff_with_tax(kwh)
       << endl;
}