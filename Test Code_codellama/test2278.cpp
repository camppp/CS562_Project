#ifndef STACK_HPP
#define STACK_HPP

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data, Node* next) : data(data), next(next) {}
    };

    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    void push(const T& value) {
        Node* newNode = new Node(value, topNode);
        topNode = newNode;
    }

    void pop() {
        if (topNode == nullptr) {
            throw std::runtime_error("Stack is empty");
        }
        Node* oldNode = topNode;
        topNode = topNode->next;
        delete oldNode;
    }

    T top() const {
        if (topNode == nullptr) {
            throw std::runtime_error("Stack is empty");
        }
        return topNode->data;
    }

    bool empty() const {
        return topNode == nullptr;
    }
};

#endif // STACK_HPP
