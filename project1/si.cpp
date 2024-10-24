#include <iostream>
#include <unordered_set>

using namespace std;

typedef unordered_set<int> Set;

int main() {
  Set s{};
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cout << !s.insert(x).second << '\n';
  }
}