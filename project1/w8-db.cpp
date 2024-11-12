#include <cstddef>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

size_t date_to_num(std::string date) {
  return std::stoull(date.substr(0, 4)) * 10000 +
         std::stoull(date.substr(5, 2)) * 100 + std::stoull(date.substr(8, 2));
}

struct Person {
  size_t dob;
  std::string father;
  std::string mother;
  bool is_alive;

  Person() = default;

  Person(size_t dob, std::string father, std::string mother, bool is_alive)
      : dob(dob), father(father), mother(mother), is_alive(is_alive) {}
};

int main() {
  size_t count = 0;

  std::map<size_t, size_t> dob_count{};
  std::unordered_map<std::string, Person> db{};

  while (true) {
    std::string code;
    std::cin >> code;
    if (code == "*")
      break;

    std::string dob;
    std::cin >> dob;
    if (dob == "*")
      break;

    size_t date = date_to_num(dob);

    std::string father, mother;
    std::cin >> father;
    if (father == "*")
      break;
    std::cin >> mother;
    if (mother == "*")
      break;

    char is_alive;
    std::cin >> is_alive;
    if (is_alive == '*')
      break;

    Person p(date, father, mother, (is_alive == 'Y'));

    dob_count[date]++;
    db[code] = p;

    std::string region;
    std::cin >> region;
    if (region == "*")
      break;

    count++;
  }

  std::map<size_t, size_t> prefix_sum(dob_count.begin(), dob_count.end());

  for (auto it = std::next(prefix_sum.begin()); it != prefix_sum.end(); it++) {
    it->second += std::prev(it)->second;
  }

  std::string token{};
  while (token != "***") {
    std::cin >> token;
    if (token == "NUMBER_PEOPLE") {
      std::cout << count << '\n';
    } else if (token == "NUMBER_PEOPLE_BORN_AT") {
      std::string date;
      std::cin >> date;
      size_t date_num = date_to_num(date);

      auto it = dob_count.find(date_num);
      if (it == dob_count.end()) {
        std::cout << 0 << '\n';
        continue;
      }

      std::cout << it->second << '\n';
    } else if (token == "NUMBER_PEOPLE_BORN_BETWEEN") {
      std::string from, to;
      std::cin >> from >> to;
      size_t date_from = date_to_num(from), date_to = date_to_num(to);

      size_t count = 0;

      for (auto it = dob_count.lower_bound(date_from);
           it != dob_count.upper_bound(date_to); it++) {
        count += it->second;
      }

      std::cout << count << '\n';
    } else if (token == "MOST_ALIVE_ANCESTOR") {
      std::string code;
      std::cin >> code;
      size_t max_depth = 0;

      std::function<void(Person, size_t)> dfs =
          [&max_depth, &db, &dfs](Person p, size_t current_depth) {
            if (p.father != "0000000" && db[p.father].is_alive) {
              dfs(db[p.father], current_depth + 1);
            }

            if (p.mother != "0000000" && db[p.mother].is_alive) {
              dfs(db[p.mother], current_depth + 1);
            }

            if (current_depth > max_depth) {
              max_depth = current_depth;
            }
          };

      dfs(db[code], 0);
      std::cout << max_depth << '\n';
    } else if (token == "MAX_UNRELATED_PEOPLE") {
      // TODO
      std::cout << 0 << '\n';
    }
  }
}