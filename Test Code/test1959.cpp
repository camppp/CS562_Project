#include <iostream>
#include <queue>

class CustomQueue {
private:
  std::queue<int> q;
  bool canEnqueue;

public:
  CustomQueue(bool canEnqueue) : canEnqueue(canEnqueue) {}

  void enqueue(int value, bool canEnqueue) {
    if (canEnqueue) {
      q.push(value);
      std::cout << "Enqueued: " << value << std::endl;
    } else {
      std::cout << "Enqueue operation not allowed based on options" << std::endl;
    }
  }

  int dequeue() {
    if (!q.empty()) {
      int front = q.front();
      q.pop();
      std::cout << "Dequeued: " << front << std::endl;
      return front;
    } else {
      std::cout << "Queue is empty" << std::endl;
      return -1; // Assuming -1 as an indicator of an empty queue
    }
  }

  bool isEmpty() {
    return q.empty();
  }
};

int main() {
  bool can_enqueue = true; // Example boolean value obtained from options
  CustomQueue queue(can_enqueue);

  queue.enqueue(5, can_enqueue);
  queue.enqueue(10, can_enqueue);
  queue.dequeue();
  queue.dequeue();
  queue.dequeue(); // Trying to dequeue from an empty queue
  return 0;
}
