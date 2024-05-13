#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

struct DSU {
 private:
  vector<int> parent;
  vector<size_t> sz;

  int find_set(int u) { return u == parent[u] ? u : parent[u] = find_set(parent[u]); }

 public:
  DSU(size_t n) : parent(n), sz(n, 1) {
    for (size_t i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  size_t get_size(size_t n) { return sz[n]; }

  bool is_connected(int u, int v) { return find_set(u) == find_set(v); }

  void union_sets(int u, int v) {
    int a = find_set(u);
    int b = find_set(v);

    if (a != b) {
      if (sz[a] < sz[b]) swap(a, b);
      parent[b] = a;
      sz[a] += sz[b];
    }
  }
};

class Solution {
 public:
  bool canTraverseAllPairs(vector<int> &nums) {
    const auto n = nums.size();
    const auto max_num = std::ranges::max(nums);
    const auto min_prime_factors = eratosthenes(max_num + 1);

    DSU dsu(n);

    unordered_map<ll, size_t> primes_first_index{};

    for (size_t i = 0; i < n; ++i) {
      for (const auto p : prime_factors(nums[i], min_prime_factors)) {
        const auto it = primes_first_index.find(p);
        if (it != primes_first_index.cend())
          dsu.union_sets(it->second, i);
        else
          primes_first_index[p] = i;
      }
    }

    for (size_t i = 0; i < n; ++i)
      if (dsu.get_size(i) == n) return true;

    return false;
  }

 private:
  // Get the minimum prime factor of a list of numbers from 2 to n (e.g.
  // `eratosthenes[12] = 2`)
  vector<ll> eratosthenes(int n) {
    vector<ll> min_prime_factors(n + 1);

    for (int i = 2; i <= n; ++i) min_prime_factors[i] = i;

    for (ll i = 2; i * i <= n; ++i)
      if (min_prime_factors[i] == i)
        for (ll j = i * i; j < n; j += i) min_prime_factors[j] = min(min_prime_factors[j], i);

    return min_prime_factors;
  }

  vector<ll> prime_factors(ll n, const vector<ll> &min_prime_factors) {
    vector<ll> prime_factors{};

    while (n > 1) {
      const auto factor = min_prime_factors[n];
      prime_factors.push_back(factor);
      while (n % factor == 0) n /= factor;
    }

    return prime_factors;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {4, 3, 12, 8};

  assert(sol.canTraverseAllPairs(nums));

  return 0;
}
