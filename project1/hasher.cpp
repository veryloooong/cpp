#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  array<int, 100000> powers{};
  powers[0] = 1;
  for (int i = 1; i < 100000; i++) {
    powers[i] = (powers[i - 1] * 256) % m;
  }

  vector<string> strings(n);
  for (int i = 0; i < n; i++) {
    cin >> strings[i];
  }

  for (const string &s : strings) {
    int hash_code = 0;

    for (size_t i = 0, n = s.size(); i < n; i++) {
      hash_code = (hash_code + (s[i] * powers[n - i - 1]) % m) % m;
    }

    cout << hash_code << endl;
  }

  return 0;
}