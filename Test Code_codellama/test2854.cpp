class Queue {
private:
    int size; // size of the queue
    int front; // index of the front element
    int rear; // index of the rear element
    int* arr; // circular array to store the elements

public:
    // constructor
    Queue(int size) {
        this->size = size;
        this->front = -1;
        this->rear = -1;
        this->arr = new int[size];
    }

    // destructor
    ~Queue() {
        delete[] arr;
    }

    // enqueue an element to the end of the queue
    void enqueue(int element) {
        if (isFull()) {
            throw std::runtime_error("Queue is full");
        }
        rear = (rear + 1) % size;
        arr[rear] = element;
    }

    // dequeue an element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        front = (front + 1) % size;
        int element = arr[front];
        arr[front] = 0;
        return element;
    }

    // get the element at the front of the queue
    int front() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        return arr[front];
    }

    // check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // check if the queue is full
    bool isFull() {
        return (rear + 1) % size == front;
    }
};
