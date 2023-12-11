#include <iostream>
#include <cstddef>

template <typename T>
class ForwardList {
public:
    ForwardList() : head(nullptr), tail(nullptr) {}

    void push_front(const T& value) {
        Node* new_node = new Node(value);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
    }

    void pop_front() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

private:
    struct Node {
        T value;
        Node* next;

        Node(const T& value) : value(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
};

template <typename T>
class Iterator {
public:
    Iterator(Node* node) : node(node) {}

    T& operator*() {
        return node->value;
    }

    Iterator& operator++() {
        node = node->next;
        return *this;
    }

    bool operator!=(const Iterator& other) {
        return node != other.node;
    }

private:
    Node* node;
};
