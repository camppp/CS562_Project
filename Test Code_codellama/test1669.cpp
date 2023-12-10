#include <iostream>
#include <vector>
#include <stdexcept>

template<class T>
class Stack {
private:
    std::vector<T> elements;

public:
    // Pushes the given element onto the top of the stack
    void push(const T& element) {
        elements.push_back(element);
    }

    // Removes the element at the top of the stack
    void pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::pop(): pop on empty stack");
        }
        elements.pop_back();
    }

    // Returns a reference to the top element of the stack
    T& top() {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::top(): top on empty stack");
        }
        return elements.back();
    }

    // Checks if the stack is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Returns the current size of the stack
    size_t size() const {
        return elements.size();
    }
};
