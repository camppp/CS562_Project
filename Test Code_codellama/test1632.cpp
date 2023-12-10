class Queue {
private:
    List* list;  // Pointer to the linked list

public:
    // Destructor
    ~Queue() {
        delete list;
    }

    // Makes an empty Queue
    void MakeEmpty() {
        list->makeEmpty();
    }

    // Adds an element to the end of the queue
    void Enqueue(int value) {
        list->add(value);
    }

    // Removes the element at the front of the queue
    int Dequeue() {
        int value = list->get(0);
        list->remove(0);
        return value;
    }

    // Returns the element at the front of the queue
    int Front() {
        return list->get(0);
    }

    // Returns the number of elements in the queue
    int Size() {
        return list->size();
    }

    // Checks if the queue is empty
    bool Empty() {
        return list->empty();
    }
};
