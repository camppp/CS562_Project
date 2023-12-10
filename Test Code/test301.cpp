#ifndef __QUEUES_PLUS_PLUS_TYPES_HPP_

#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* frontPtr;
    Node* rearPtr;

public:
    Queue() : frontPtr(nullptr), rearPtr(nullptr) {}

    void enqueue(const T& val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            frontPtr = newNode;
            rearPtr = newNode;
        } else {
            rearPtr->next = newNode;
            rearPtr = newNode;
        }
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        T frontData = frontPtr->data;
        Node* temp = frontPtr;
        frontPtr = frontPtr->next;
        delete temp;
        if (frontPtr == nullptr) {
            rearPtr = nullptr;
        }
        return frontData;
    }

    T front() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return frontPtr->data;
    }

    bool isEmpty() {
        return frontPtr == nullptr;
    }

    ~Queue() {
        while (frontPtr != nullptr) {
            Node* temp = frontPtr;
            frontPtr = frontPtr->next;
            delete temp;
        }
        rearPtr = nullptr;
    }
};

#endif /// !__QUEUES_PLUS_PLUS_TYPES_HPP_
