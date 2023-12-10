#include <iostream>
#include <vector>
#include <stdexcept>

template<class T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(const T& element) {
        elements.push_back(element);
    }

    void pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::pop(): pop on empty stack");
        }
        elements.pop_back();
    }

    T& top() {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::top(): top on empty stack");
        }
        return elements.back();
    }

    bool isEmpty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

int main() {
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    while (!intStack.isEmpty()) {
        std::cout << intStack.top() << " ";
        intStack.pop();
    }
    std::cout << std::endl;

    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");

    while (!stringStack.isEmpty()) {
        std::cout << stringStack.top() << " ";
        stringStack.pop();
    }
    std::cout << std::endl;

    return 0;
}
