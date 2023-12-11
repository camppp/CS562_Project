template <typename T>
class LinkedList {
public:
    // Constructor
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor
    ~LinkedList() {
        clear();
    }

    // Member functions
    void push_front(const T& value) {
        Node<T>* node = new Node<T>(value);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head = node;
        }
        size++;
    }

    void pop_front() {
        if (head == nullptr) {
            return;
        }
        Node<T>* node = head;
        head = head->next;
        delete node;
        size--;
    }

    void clear() {
        while (head != nullptr) {
            pop_front();
        }
    }

    size_t size() const {
        return size;
    }

    bool empty() const {
        return size == 0;
    }

private:
    // Node structure
    struct Node {
        T value;
        Node* next;

        Node(const T& value) : value(value), next(nullptr) {}
    };

    // Head and tail pointers
    Node<T>* head;
    Node<T>* tail;

    // Size of the list
    size_t size;
};
