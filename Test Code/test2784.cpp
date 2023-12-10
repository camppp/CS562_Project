#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class RedoDelete {
private:
    Node* top;

public:
    RedoDelete() : top(nullptr) {}

    void redo(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void deleteTop() {
        if (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    ~RedoDelete() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    RedoDelete stack;
    stack.redo(5);
    stack.redo(10);
    stack.redo(15);
    stack.deleteTop();
    stack.redo(20);
    stack.deleteTop();
    return 0;
}
