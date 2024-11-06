#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <utility>

int main() {
  std::string token{};

  // using transaction_t = std::pair<std::string, int32_t>;
  // std::map<std::string, std::set<transaction_t>> transactions{};
  std::map<std::string, std::map<std::string, int32_t>> transactions{};
  size_t transaction_count = 0;
  int64_t total_amount = 0;
  std::set<std::string> accounts{};

  do {
    std::cin >> token;
    if (token == "#")
      break;
    std::string from = token;
    std::cin >> token;
    if (token == "#")
      break;
    std::string to = token;
    std::cin >> token;
    if (token == "#")
      break;
    int32_t amount = std::stoi(token);
    std::cin >> token;
    if (token == "#")
      break;
    std::string time = token;
    std::cin >> token;
    if (token == "#")
      break;
    std::string atm = token;

    transaction_count++;
    total_amount += amount;
    accounts.insert(from);
    accounts.insert(to);

    // if (from != to)
    transactions[from][to] += amount;
  } while (token != "#");

  do {
    std::cin >> token;
    if (token == "?number_transactions") {
      std::cout << transaction_count << '\n';
    } else if (token == "?total_money_transaction") {
      std::cout << total_amount << '\n';
    } else if (token == "?list_sorted_accounts") {
      for (const std::string &account : accounts) {
        std::cout << account << ' ';
      }
      std::cout << '\n';
    } else if (token == "?total_money_transaction_from") {
      std::string acct;
      std::cin >> acct;
      int64_t total = 0;
      for (const auto &[_, amt] : transactions[acct]) {
        total += amt;
      }
      std::cout << total << '\n';
    } else if (token == "?inspect_cycle") {
      std::string account;
      size_t len;
      std::cin >> account >> len;

      // perform dls
      std::stack<std::pair<std::string, size_t>> stk{};
      std::set<std::string> visited{};
      stk.push({account, 0});
      bool found = false;

      std::function<void(const std::string &, size_t)> dls_cycle =
          [&transactions, &len, &found, &account, &visited,
           &dls_cycle](const std::string &current, size_t depth) {
            if (depth == len) {
              if (current == account) {
                found = true;
              }
              return;
            }

            if (visited.find(current) != visited.end()) {
              return;
            }

            visited.insert(current);
            for (const auto &[next, _] : transactions[current]) {
              dls_cycle(next, depth + 1);
            }
            visited.erase(current);
          };

      dls_cycle(account, 0);

      std::cout << found << '\n';
    }
  } while (token != "#");
}