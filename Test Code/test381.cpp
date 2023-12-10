++
#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    int peek() {
        if (top) {
            return top->data;
        }
        return -1; // Assuming stack contains only positive integers
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void executeProvidedCodeSnippet(bool iosActor) {
        if (!iosActor) {
            return;
        }
        // Execute the provided code snippet
        // ...
    }
};

int main() {
    Stack stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);

    std::cout << "Top element: " << stack.peek() << std::endl; // Output: 15

    stack.pop();
    std::cout << "Top element after pop: " << stack.peek() << std::endl; // Output: 10

    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl; // Output: No

    stack.executeProvidedCodeSnippet(true); // Execute the provided code snippet

    return 0;
}
