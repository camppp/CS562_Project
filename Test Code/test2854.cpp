#include <iostream>

class Queue {
private:
    int front, rear, capacity;
    int* array;

public:
    Queue(int size) {
        capacity = size;
        front = 0;
        rear = 0;
        array = new int[capacity];
    }

    ~Queue() {
        delete[] array;
    }

    void enqueue(int item) {
        if ((rear + 1) % capacity == front) {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }
        array[rear] = item;
        rear = (rear + 1) % capacity;
    }

    void dequeue() {
        if (front == rear) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }
        front = (front + 1) % capacity;
    }

    int frontElement() {
        if (front == rear) {
            std::cout << "Queue is empty. No front element." << std::endl;
            return -1; // Assuming -1 as an invalid value
        }
        return array[front];
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};

int main() {
    Queue queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    std::cout << "Front element: " << queue.frontElement() << std::endl;
    queue.dequeue();
    std::cout << "Front element after dequeue: " << queue.frontElement() << std::endl;
    std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Is queue full? " << (queue.isFull() ? "Yes" : "No") << std::endl;

    return 0;
}
