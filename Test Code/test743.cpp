#include <iostream>

template <class T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };
    Node* topNode;

public:
    // Implement the push operation to add a new element to the top of the stack
    void push(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    // Implement the pop operation to remove the top element from the stack and return its value
    T pop() {
        if (topNode == nullptr) {
            throw std::out_of_range("Stack is empty");
        }
        T value = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return value;
    }

    // Implement the top operation to return the value of the top element without removing it
    T top() {
        if (topNode == nullptr) {
            throw std::out_of_range("Stack is empty");
        }
        return topNode->data;
    }

    // Implement the empty operation to check if the stack is empty
    bool empty() {
        return topNode == nullptr;
    }
};
