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
    void push(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    T pop() {
        if (topNode == nullptr) {
            throw std::runtime_error("Stack is empty");
        }
        T value = topNode->data;
        Node* oldNode = topNode;
        topNode = topNode->next;
        delete oldNode;
        return value;
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
};
#endif //RHI_COMPLETE
}
};
