#include <climits>

struct Node {
    int data;
    Node* next;
};

void push(Node* &top, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop(Node* &top) {
    if (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

int top(Node* top) {
    if (top != nullptr) {
        return top->data;
    }
    return INT_MIN;  // Return minimum integer value if stack is empty
}

int getMin(Node* top) {
    int minVal = INT_MAX;  // Initialize with maximum integer value
    Node* current = top;
    while (current != nullptr) {
        if (current->data < minVal) {
            minVal = current->data;
        }
        current = current->next;
    }
    return minVal;
}
