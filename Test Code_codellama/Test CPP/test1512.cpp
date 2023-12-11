#include <iostream>

class Node {
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value = value;
            this->next = nullptr;
        }
};

int remove_last_element(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current->next != nullptr) {
        previous = current;
        current = current->next;
    }

    int removed_value = current->value;
    if (previous != nullptr) {
        previous->next = nullptr;
    } else {
        head = nullptr;
    }

    delete current;
    return removed_value;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int removed_value = remove_last_element(head);
    std::cout << "Removed value: " << removed_value << std::endl;

    return 0;
}
