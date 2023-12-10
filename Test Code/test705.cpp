#include <iostream>

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // Function to insert a new element at the beginning of the list
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    // Function to delete a specified element from the list
    void deleteElement(int val) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == val) {
                if (current == head) {
                    head = current->next;
                }
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    // Function to traverse the list in the forward direction and print the elements
    void traverseForward() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Function to traverse the list in the backward direction and print the elements
    void traverseBackward() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.insertAtBeginning(1);
    list.insertAtBeginning(2);
    list.insertAtBeginning(3);
    list.deleteElement(2);
    list.traverseForward();
    list.traverseBackward();
    return 0;
}
