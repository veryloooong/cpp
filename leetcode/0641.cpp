#include <vector>

class MyCircularDeque {
private:
  size_t bufferSize;
  size_t frontIdx, backIdx, size;
  std::vector<int> buffer;

public:
  MyCircularDeque(int k)
      : bufferSize(k), frontIdx(0), backIdx(k - 1), size(0), buffer(k) {}

  bool insertFront(int value) {
    if (isFull())
      return false;

    size++;
    frontIdx = (frontIdx - 1 + bufferSize) % bufferSize;
    buffer[frontIdx] = value;

    return true;
  }

  bool insertLast(int value) {
    if (isFull())
      return false;

    size++;
    backIdx = (backIdx + 1) % bufferSize;
    buffer[backIdx] = value;

    return true;
  }

  bool deleteFront() {
    if (isEmpty())
      return false;

    size--;
    frontIdx = (frontIdx + 1) % bufferSize;

    return true;
  }

  bool deleteLast() {
    if (isEmpty())
      return false;

    size--;
    backIdx = (backIdx - 1 + bufferSize) % bufferSize;

    return true;
  }

  int getFront() { return isEmpty() ? -1 : buffer[frontIdx]; }

  int getRear() { return isEmpty() ? -1 : buffer[backIdx]; }

  bool isEmpty() { return size == 0; }

  bool isFull() { return size == bufferSize; }
};