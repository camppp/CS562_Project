#include <iostream>

namespace ui {
  struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
  };

  class CustomStack {
  private:
    Node* topNode;

  public:
    CustomStack() : topNode(nullptr) {}

    void push(int val) {
      Node* newNode = new Node(val);
      newNode->next = topNode;
      topNode = newNode;
    }

    int pop() {
      if (topNode == nullptr) {
        std::cerr << "Error: Stack is empty" << std::endl;
        return -1;  // Assuming -1 as an error value
      }
      int val = topNode->data;
      Node* temp = topNode;
      topNode = topNode->next;
      delete temp;
      return val;
    }

    int top() {
      if (topNode == nullptr) {
        std::cerr << "Error: Stack is empty" << std::endl;
        return -1;  // Assuming -1 as an error value
      }
      return topNode->data;
    }

    bool empty() {
      return topNode == nullptr;
    }
  };
}  // namespace ui
