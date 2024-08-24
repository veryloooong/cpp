#include <iostream>
#include <numeric>
#include <string>
#include <utility>

enum State {
  Num,
  Den,
};

class Solution {
private:
  typedef std::pair<int, int> Fraction;
  Fraction addFractions(Fraction a, Fraction b) {
    int commonDenominator = std::lcm(a.second, b.second);
    int factorA = commonDenominator / a.second,
        factorB = commonDenominator / b.second;

    Fraction result = {a.first * factorA + b.first * factorB,
                       commonDenominator};
    int reductor = std::gcd(result.first, result.second);
    result = {result.first / reductor, result.second / reductor};

    return result;
  }

public:
  std::string fractionAddition(std::string expression) {
    int num = 0;
    int den = 0;
    int sign = 1;
    State state = State::Num;
    Fraction result{0, 1};

    for (const char &c : expression) {
      // lol
      if (c == '+' || c == '-') {
        Fraction current = {sign * num, den > 0 ? den : 1};
        result = addFractions(result, current);

        state = State::Num;
        if (c == '+')
          sign = 1;
        else
          sign = -1;

        num = 0;
        den = 0;
      } else if (c == '/') {
        state = State::Den;
      } else {
        if (state == State::Num) {
          num = num * 10 + (c - '0');
        } else {
          den = den * 10 + (c - '0');
        }
      }
    }

    Fraction current = {sign * num, den > 0 ? den : 1};
    result = addFractions(result, current);

    return std::to_string(result.first) + "/" + std::to_string(result.second);
  }
};

int main() {
  std::string exp = "-1/2+1/2";
  std::cout << Solution().fractionAddition(exp) << std::endl;
}