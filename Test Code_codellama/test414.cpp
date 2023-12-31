#include <iostream>
#include <string>

template <class T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

template <class T>
class Stack {
private:
    Node<T>* topNode;

public:
    Stack() : topNode(nullptr) {}

    void push(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = topNode;
        topNode = newNode;
    }

    T pop() {
        if (topNode == nullptr) {
            throw std::runtime_error("Stack is empty");
        }
        T val = topNode->data;
        Node<T>* oldNode = topNode;
        topNode = topNode->next;
        delete oldNode;
        return val;
    }

    T top() {
        if (topNode == nullptr) {
            throw std::runtime_error("Stack is empty");
        }
        return topNode->data;
    }

    bool empty() {
        return topNode == nullptr;
    }

    ~Stack() {
        while (topNode != nullptr) {
            Node<T>* oldNode = topNode;
            topNode = topNode->next;
            delete oldNode;
        }
    }
};

int main() {
    // Test your stack implementation here
    Stack<int> intStack;
    intStack.push(5);
    intStack.push(10);
    std::cout << intStack.top() << std::endl;
    intStack.pop();
    std::cout << intStack.top() << std::endl;

    Stack<char> charStack;
    charStack.push('a');
    charStack.push('b');
    std::cout << charStack.top() << std::endl;
    charStack.pop();
    std::cout << charStack.top() << std::endl;

    Stack<std::string> stringStack;
    stringStack.push("hello");
    stringStack.push("world");
    std::cout << stringStack.top() << std::endl;
    stringStack.pop();
    std::cout << stringStack.top() << std::endl;

    return 0;
}
