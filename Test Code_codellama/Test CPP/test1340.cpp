// stack.cpp
#include "stack.h"

void Stack::push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void Stack::pop() {
    if (top == nullptr) {
        throw std::runtime_error("Stack is empty");
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

int Stack::peek() {
    if (top == nullptr) {
        throw std::runtime_error("Stack is empty");
    }
    return top->data;
}

bool Stack::isEmpty() {
    return top == nullptr;
}
