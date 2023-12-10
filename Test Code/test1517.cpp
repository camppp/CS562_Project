#include <iostream>

namespace ui {

class Stack {
private:
    struct Node {
        int val;
        Node* next;
    };

    Node* head;

public:
    Stack() {
        head = nullptr;
    }

    void push(int val) {
        Node* newNode = new Node();
        newNode->val = val;
        newNode->next = head;
        head = newNode;
    }

    int pop() {
        if (head == nullptr) {
            throw std::runtime_error("Stack is empty");
        }

        int val = head->val;
        Node* temp = head;
        head = head->next;
        delete temp;
        return val;
    }

    int top() {
        if (head == nullptr) {
            throw std::runtime_error("Stack is empty");
        }

        return head->val;
    }

    bool empty() {
        return head == nullptr;
    }
};

} // namespace ui
