#include <iostream>
#include <cassert>

struct Node {
    int val;
    int min;
    Node* next;
    Node(int x, int m, Node* n) : val(x), min(m), next(n) {}
};

class MinStack {
private:
    Node* topNode;

public:
    MinStack() {
        topNode = nullptr;
    }

    void push(int x) {
        if (topNode == nullptr) {
            topNode = new Node(x, x, nullptr);
        } else {
            topNode = new Node(x, std::min(x, topNode->min), topNode);
        }
    }

    void pop() {
        assert(topNode != nullptr);  // Ensure stack is not empty
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() {
        assert(topNode != nullptr);  // Ensure stack is not empty
        return topNode->val;
    }

    int getMin() {
        assert(topNode != nullptr);  // Ensure stack is not empty
        return topNode->min;
    }
};

int main() {
    MinStack stack;
    stack.push(5);
    stack.push(3);
    stack.push(7);
    stack.push(2);

    std::cout << "Top element: " << stack.top() << std::endl;  // Output: 2
    std::cout << "Minimum element: " << stack.getMin() << std::endl;  // Output: 2

    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl;  // Output: 7
    std::cout << "Minimum element after pop: " << stack.getMin() << std::endl;  // Output: 3

    return 0;
}
