#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;

constexpr ll MOD = 1e9 + 7; // NOLINT

static constexpr ull ct_sqrt(ull res, ull l, ull r) {
  if (l == r) {
    return r;
  } else {
    const auto mid = (r + l) / 2;

    if (mid * mid >= res) {
      return ct_sqrt(res, l, mid);
    } else {
      return ct_sqrt(res, mid + 1, r);
    }
  }
}

// Compile-time square root
static constexpr ull ct_sqrt(ull res) { return ct_sqrt(res, 1, res); } // NOLINT

// Binary exponential
constexpr ull expo(ull base, ull exponent) {
  ull result = 1;

  while (exponent > 0) {
    if (exponent & 1) {
      result = (result * base) % MOD;
    }
    base = (base * base) % MOD;
    exponent >>= 1;
  }
  return result;
}

class MyQueue {
private:
  vector<int> vector_main;
  vector<int> vector_help;

  void bad_idea_lol() {
    auto n = vector_main.size();
    auto m = vector_help.size();
    if (m == 0) {
      for (size_t i = 0; i < n; ++i) {
        int x = vector_main.back();
        vector_help.push_back(x);
        vector_main.pop_back();
      }
    }
  }

public:
  MyQueue() {
    vector_main = {};
    vector_help = {};
  }
  void push(int x) { vector_main.push_back(x); }
  int pop() {
    bad_idea_lol();
    int x = vector_help.back();
    vector_help.pop_back();
    return x;
  }
  int peek() {
    bad_idea_lol();
    int x = vector_help.back();
    return x;
  }
  bool empty() { return vector_main.empty() && vector_help.empty(); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  MyQueue q;
  q.push(1);
  q.push(2);
  q.push(3);

  cout << q.peek();

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */