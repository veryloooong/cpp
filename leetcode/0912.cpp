#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class Solution {
private:
  void heapify(vector<int> &nums, int i, int sz) {
    int n = sz;
    while (true) {
      int leftChild = 2 * i + 1;
      int rightChild = 2 * i + 2;

      int maxChild;

      if (leftChild >= n && rightChild >= n)
        break;

      if (rightChild >= n)
        maxChild = leftChild;
      else
        maxChild = nums[leftChild] > nums[rightChild] ? leftChild : rightChild;

      int current = nums[i];
      if (current > nums[maxChild])
        break;
      else {
        swap(nums[i], nums[maxChild]);
        i = maxChild;
      }
    }
  }

  void buildMaxHeap(vector<int> &nums) {
    for (int i = nums.size() / 2; i >= 0; i--) {
      heapify(nums, i, nums.size());
    }
  }

public:
  vector<int> sortArray(vector<int> &nums) {
    buildMaxHeap(nums);
    for (int i = nums.size() - 1; i >= 1; i--) {
      swap(nums[0], nums[i]);
      heapify(nums, 0, i);
    }
    return nums;
  }
};

int main() { return 0; }