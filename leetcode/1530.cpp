#include <vector>

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
private:
  std::vector<int> dfs(TreeNode *current, int distance, int &cnt) {
    std::vector<int> leaves_per_height(distance + 1);
    if (current == nullptr)
      return leaves_per_height;
    if (current->left == nullptr && current->right == nullptr) {
      leaves_per_height[0] = 1;
      return leaves_per_height;
    }

    std::vector<int> dfs_left = dfs(current->left, distance, cnt);
    std::vector<int> dfs_right = dfs(current->right, distance, cnt);

    for (int i = 0; i < distance; i++)
      for (int j = 0; j < distance; j++)
        if (i + j + 2 <= distance)
          cnt += dfs_left[i] * dfs_right[j];

    for (int i = 0; i < distance; i++)
      leaves_per_height[i + 1] = dfs_left[i] + dfs_right[i];

    return leaves_per_height;
  }

public:
  int countPairs(TreeNode *root, int distance) {
    int ans = 0;

    dfs(root, distance, ans);

    return ans;
  }
};

int main() { return 0; }