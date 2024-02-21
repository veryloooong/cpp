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

constexpr size_t ALPHABET_SIZE = 26;

constexpr size_t char_to_idx(char c) { return c - 'a'; }
constexpr char idx_to_char(size_t i) { return 'a' + i; }

struct TrieNode {
  array<shared_ptr<TrieNode>, ALPHABET_SIZE> children;
  bool is_leaf;

  TrieNode() : children(), is_leaf(false) {}

  // idk how to write a proper dtor in C++ so i named it drop like it's Rust
  // xdddd
  void drop() {
    for (size_t i = 0; i < ALPHABET_SIZE; ++i) {
      if (children[i] != nullptr) {
        children[i]->drop();
        children[i].reset();
      }
    }
  }

  // the actual dtor calls drop...
  ~TrieNode() { drop(); }

  pair<size_t, size_t> num_children_and_index() {
    size_t count = 0;
    size_t index = 0;

    for (size_t i = 0; i < ALPHABET_SIZE; ++i) {
      if (children[i] != nullptr) {
        count++;
        index = i;
      }
    }

    return make_pair(count, index);
  }
};

struct Trie {
private:
  shared_ptr<TrieNode> root;

public:
  Trie() : root(make_shared<TrieNode>()) {}
  ~Trie() { root.reset(); }

  void insert(const string &word) {
    shared_ptr<TrieNode> current = root;
    for (char c : word) {
      int idx = char_to_idx(c);
      if (current->children[idx] == nullptr) {
        current->children[idx] = make_shared<TrieNode>();
      }
      current = current->children[idx];
    }
    current->is_leaf = true;
  }

  bool search(const string &word) {
    shared_ptr<TrieNode> current = root;
    for (char c : word) {
      int idx = char_to_idx(c);
      if (current->children[idx] == nullptr) {
        return false;
      }
      current = current->children[idx];
    }
    return current->is_leaf;
  }

  string prefix() {
    shared_ptr<TrieNode> current = root;
    string pref{};
    pair<size_t, size_t> ci = current->num_children_and_index();

    while (ci.first == 1 && !current->is_leaf) {
      auto idx = ci.second;
      pref.push_back(idx_to_char(idx));
      current = current->children[idx];
      ci = current->num_children_and_index();
    }

    return pref;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Trie trie{};
  string s1 = "yeah";
  trie.insert(s1);
  string s2 = "yes";
  trie.insert(s2);

  assert(trie.search("yeah"));
  assert(!trie.search("lol"));

  cout << trie.prefix();

  return 0;
}

/* uuuuuuuuuuuuuuu - Ceres Fauna (2021 - ) */