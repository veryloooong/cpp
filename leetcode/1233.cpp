#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

class Solution {
public:
  vector<string> removeSubfolders(vector<string> &folder) {
    sort(folder.begin(), folder.end());
    vector<string> result;

    string parent = folder[0];

    for (size_t i = 1; i < folder.size(); i++) {
      if (folder[i].find(parent + "/") == string::npos ||
          folder[i].find(parent + "/") != 0) {
        result.push_back(parent);
        parent = folder[i];
      }
    }

    result.push_back(parent);

    return result;
  }
};

int main() {
  vector<string> folder = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
  Solution solution;
  vector<string> result = solution.removeSubfolders(folder);
  for (const string &r : result) {
    cout << r << endl;
  }

  cout << "=====================" << endl;

  folder = {"/a", "/a/b/c", "/a/b/d"};
  result = solution.removeSubfolders(folder);
  for (const string &r : result) {
    cout << r << endl;
  }

  cout << "=====================" << endl;

  folder = {"/a/b/c", "/a/b/ca", "/a/b/d"};
  result = solution.removeSubfolders(folder);
  for (const string &r : result) {
    cout << r << endl;
  }

  return 0;
}