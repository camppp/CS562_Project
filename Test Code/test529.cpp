#include "nodeList.hpp"

class Node {
public:
    Statement data;
    Node* next;

    Node(const Statement& statement) : data(statement), next(nullptr) {}
};

class NodeList : public Statement {
private:
    Node* head;

public:
    NodeList() : head(nullptr) {}

    ~NodeList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void append(const Statement& statement) {
        Node* newNode = new Node(statement);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void remove(int index) {
        if (index < 0) {
            return;
        }
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            for (int i = 0; current != nullptr && i < index - 1; i++) {
                current = current->next;
            }
            if (current == nullptr || current->next == nullptr) {
                return;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            current->data.print();  // Assuming Statement has a print method
            current = current->next;
        }
    }
};
