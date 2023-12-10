template <typename Type>
class Priority_queue {
private:
    Data_pq<Type> *first;

public:
    // Constructor
    Priority_queue() : first(nullptr) {}

    // Destructor
    ~Priority_queue() {
        while (first != nullptr) {
            Data_pq<Type> *temp = first;
            first = first->return_p_next_data();
            delete temp;
        }
    }

    // Add an element to the priority queue with a specified priority
    void push(Type new_data, int new_priority) {
        Data_pq<Type> *new_node = new Data_pq<Type>(new_data, new_priority);
        if (first == nullptr) {
            first = new_node;
        } else {
            Data_pq<Type> *current = first;
            while (current->return_priority() > new_priority) {
                current = current->return_p_next_data();
            }
            new_node->set_p_next_data(current);
            current->set_p_next_data(new_node);
        }
    }

    // Remove the element with the highest priority from the priority queue
    void pop() {
        if (first == nullptr) {
            return;
        }
        Data_pq<Type> *temp = first;
        first = first->return_p_next_data();
        delete temp;
    }

    // Retrieve the element with the highest priority without removing it from the priority queue
    Type top() {
        if (first == nullptr) {
            return nullptr;
        }
        return first->return_data();
    }

    // Check if the priority queue is empty
    bool empty() {
        return first == nullptr;
    }
};
