#include <iostream>

class Stack {
private:
    int *arr;
    int topIndex;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    void push(int val) {
        if (topIndex == capacity - 1) {
            std::cout << "Stack overflow" << std::endl;
            return;
        }
        arr[++topIndex] = val;
    }

    int pop() {
        if (topIndex == -1) {
            std::cout << "Stack underflow" << std::endl;
            return -1;
        }
        return arr[topIndex--];
    }

    int top() {
        if (topIndex == -1) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    ~Stack() {
        delete[] arr;
    }
};
