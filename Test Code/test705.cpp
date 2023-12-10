#include <iostream>

void DoublyLinkedList::insertAtBeginning(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DoublyLinkedList::deleteElement(int val) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == val) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
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

void DoublyLinkedList::traverseForward() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::traverseBackward() {
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

int main() {
    DoublyLinkedList list;
    list.insertAtBeginning(3);
    list.insertAtBeginning(5);
    list.insertAtBeginning(7);
    list.insertAtBeginning(9);
    list.traverseForward();  // Output: 9 7 5 3
    list.traverseBackward(); // Output: 3 5 7 9
    list.deleteElement(5);
    list.traverseForward();  // Output: 9 7 3
    list.traverseBackward(); // Output: 3 7 9
    return 0;
}
