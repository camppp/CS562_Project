#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void deleteNode(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                Node* temp = current;
                current = current->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }

    void traverse() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void reverse() {
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr) {
            Node* temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }
        head = previous;
    }
};

int main() {
    LinkedList list;
    list.insertAtBeginning(3);
    list.insertAtBeginning(5);
    list.insertAtBeginning(7);
    list.traverse(); // Output: 7 5 3
    list.deleteNode(5);
    list.traverse(); // Output: 7 3
    list.reverse();
    list.traverse(); // Output: 3 7
    return 0;
}
