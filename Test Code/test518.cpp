#include <cstddef>

class cMessage {
    // Assume cMessage implementation
};

class Queue {
private:
    struct Node {
        cMessage *data;
        Node *next;
    };

    Node *front;
    Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void pushPacket(cMessage *packet) {
        Node *newNode = new Node{packet, nullptr};
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    cMessage *popPacket() {
        if (isEmpty()) {
            return nullptr;
        } else {
            Node *temp = front;
            cMessage *packet = temp->data;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete temp;
            return packet;
        }
    }

    ~Queue() {
        while (front != nullptr) {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }
};

class MacProtocolBase {
private:
    Queue *txQueue;

public:
    MacProtocolBase() : txQueue(new Queue()) {}

    void clearQueue() {
        while (!txQueue->isEmpty()) {
            delete txQueue->popPacket();
        }
    }

    void handleMessageWhenDown(cMessage *msg) {
        // Implementation for handling messages when the protocol is down
    }
};
