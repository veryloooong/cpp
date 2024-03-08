#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxFrequencyElements(vector<int> &nums) {
    unordered_map<int, size_t> freqs{};
    size_t max_freq = 0;
    for (const int x : nums) {
      freqs[x]++;
      max_freq = max(freqs[x], max_freq);
    }
    int count = 0;
    for (const auto [_, freq] : freqs)
      if (freq == max_freq)
        count++;
    return count * max_freq;
  }
};

int main() {}