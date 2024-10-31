#include <algorithm>
#include <cstdint>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());

    map<int, int> times{};

    for (vector<int> &interval : intervals) {
      int s = interval[0];
      int e = interval[1];

      auto slot = times.upper_bound(e);

      if (slot == times.begin() || std::prev(slot)->second < s) {
        times[s] = e;
      } else {
        auto overlap = std::prev(slot);
        int ss = overlap->first;

        int ns = std::min(overlap->first, s);
        int ne = std::max(overlap->second, e);

        times.erase(ss);
        times[ns] = ne;

        // do start merging
        auto new_it = times.find(ns);
        if (std::prev(new_it)->second >= ns) {
          int bigns = std::prev(new_it)->first;
          times[bigns] = ne;
          ns = bigns;
        }

        // remove inside overlaps
        new_it = times.find(ns);
        auto first_next = std::next(new_it);
        if (first_next == times.end() || first_next->first > new_it->second)
          continue;
        times.erase(first_next, times.upper_bound(ne));
      }
    }

    vector<vector<int>> ans{};

    for (const auto [s, e] : times) {
      ans.push_back({s, e});
    }

    return ans;
  }
};

int main() {
  vector<vector<int>> intervals = {{0, 2}, {2, 3}, {4, 4}, {0, 1},
                                   {5, 7}, {4, 5}, {0, 0}};

  Solution().merge(intervals);
}