#include <bits/stdc++.h>

using namespace std;

struct DSU {
private:
  vector<int> parent;
  vector<int> sz;

  int find_set(int v) {
    return parent[v] == v ? v : parent[v] = find_set(parent[v]);
  }

public:
  DSU(int n) : parent(n), sz(n) {
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
      sz[i]++;
    }
  }

  void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
  }

  void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
      if (sz[a] < sz[b])
        swap(a, b);
      parent[b] = a;
      sz[a] += sz[b];
    }
  }

  bool is_connected(int a, int b) { return find_set(a) == find_set(b); }
};

vector<int> find_all_people(int n, vector<vector<int>> &meetings,
                            int firstPerson) {
  vector<int> ans{};

  map<int, vector<pair<int, int>>> times{};

  for (const auto &meeting : meetings) {
    times[meeting[2]].push_back({meeting[0], meeting[1]});
  }

  DSU dsu(n);
  dsu.union_sets(0, firstPerson);

  for (const auto &[_, pairs] : times) {
    unordered_set<int> people{};
    for (const auto &[a, b] : pairs) {
      dsu.union_sets(a, b);
      people.insert(a);
      people.insert(b);
    }
    for (const auto person : people)
      if (!dsu.is_connected(0, person))
        dsu.make_set(person);
  }

  for (int i = 0; i < n; ++i)
    if (dsu.is_connected(0, i))
      ans.push_back(i);

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n = 4;
  vector<vector<int>> meetings = {{3, 1, 3}, {1, 2, 2}, {0, 3, 3}};
  int firstPerson = 3;

  auto ans = find_all_people(n, meetings, firstPerson);

  for (auto x : ans)
    cout << x << " ";
  cout << endl;

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */