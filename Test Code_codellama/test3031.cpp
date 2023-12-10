#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    void display() {
        cout << data << " ";
    }
};

void display() {
    Node* current = head;
    while (current != nullptr) {
        current->display();
        current = current->next;
    }
}
