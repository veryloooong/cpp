#include <cstddef>
#include <cstdint>
#include <ios>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <unordered_map>

int64_t hms_to_seconds(std::string timestamp) {
  return std::stoll(timestamp.substr(0, 2)) * 3600 +
         std::stoll(timestamp.substr(3, 2)) * 60 +
         std::stoll(timestamp.substr(6, 2));
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string token{};

  size_t orders = 0;
  int64_t total_revenue = 0;

  std::unordered_map<std::string, std::unordered_map<std::string, int64_t>>
      shop_revenue{};
  std::map<int64_t, int64_t> timestamp_revenue{};

  do {
    std::cin >> token;
    if (token == "#")
      break;
    std::string customer = token;
    std::cin >> token;
    if (token == "#")
      break;
    std::string product = token;
    std::cin >> token;
    if (token == "#")
      break;
    int64_t price = std::stoll(token);
    std::cin >> token;
    if (token == "#")
      break;
    std::string shop_id = token;
    std::cin >> token;
    if (token == "#")
      break;
    int64_t timestamp = hms_to_seconds(token);

    orders++;
    total_revenue += price;
    shop_revenue[shop_id][customer] += price;
    timestamp_revenue[timestamp] += price;
    // timestamp_revenue.insert(timestamp, timestamp, price);
  } while (token != "#");

  for (auto it = std::next(timestamp_revenue.begin());
       it != timestamp_revenue.end(); it++) {
    it->second += std::prev(it)->second;
  }

  do {
    std::cin >> token;
    if (token == "?total_number_orders") {
      std::cout << orders << '\n';
    } else if (token == "?total_revenue") {
      std::cout << total_revenue << '\n';
    } else if (token == "?revenue_of_shop") {
      std::string shop;
      std::cin >> shop;
      int64_t revenue = 0;
      for (const auto &[_, value] : shop_revenue[shop]) {
        revenue += value;
      }
      std::cout << revenue << '\n';
    } else if (token == "?total_consume_of_customer_shop") {
      std::string customer, shop;
      std::cin >> customer >> shop;
      std::cout << shop_revenue[shop][customer] << '\n';
    } else if (token == "?total_revenue_in_period") {
      std::string start, end;
      std::cin >> start >> end;
      int64_t start_seconds = hms_to_seconds(start);
      int64_t end_seconds = hms_to_seconds(end);

      auto start_it = timestamp_revenue.lower_bound(start_seconds);
      auto end_it = std::prev(timestamp_revenue.upper_bound(end_seconds));

      int64_t start_revenue = 0;
      if (start_it != timestamp_revenue.begin()) {
        start_revenue = std::prev(start_it)->second;
      }

      if (start_it == timestamp_revenue.end() ||
          end_it == timestamp_revenue.end()) {
        std::cout << 0 << '\n';
        continue;
      }

      int64_t revenue = end_it->second - start_revenue;

      std::cout << revenue << '\n';
    }
  } while (token != "#");
}