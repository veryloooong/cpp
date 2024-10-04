#include <string>
#include <unordered_map>

using std::string;

class AllOne {
  std::unordered_map<string, int> freqs;
  std::unordered_map<string, int>::iterator maxKey, minKey;

public:
  AllOne() : freqs(), maxKey(freqs.end()), minKey(freqs.end()) {}

  void inc(string key) {
    if (maxKey->second < (++freqs[key])) {
      maxKey = freqs.find(key);
    }
  }

  void dec(string key) {
    if (--freqs[key] == 0) {
      freqs.erase(key);
    }
  }

  string getMaxKey() { return maxKey->first; }

  string getMinKey() { return minKey->first; }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */