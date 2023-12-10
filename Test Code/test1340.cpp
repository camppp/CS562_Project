// stack.cpp
#include "stack.h"

void Stack::push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void Stack::pop() {
    if (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

int Stack::peek() {
    if (top != nullptr) {
        return top->data;
    }
    // Return a default value if the stack is empty
    return -1;
}

bool Stack::isEmpty() {
    return top == nullptr;
}
