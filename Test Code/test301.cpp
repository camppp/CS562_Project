#ifndef __QUEUES_PLUS_PLUS_TYPES_HPP_
#define __QUEUES_PLUS_PLUS_TYPES_HPP_

#include <iostream>
#include <vector>

template <typename T>
class Queue {
private:
    std::vector<T> queue;
    int front_index;
    int rear_index;

public:
    Queue() : front_index(0), rear_index(0) {}

    void enqueue(T val) {
        queue.push_back(val);
        rear_index++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }

        T front_val = queue[front_index];
        front_index++;
        return front_val;
    }

    T front() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }

        return queue[front_index];
    }

    bool isEmpty() {
        return front_index == rear_index;
    }
};

#endif /// !__QUEUES_PLUS_PLUS_TYPES_HPP_
