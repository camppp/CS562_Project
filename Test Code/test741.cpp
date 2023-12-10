// Destructor
template <typename Type>
Priority_queue<Type>::~Priority_queue() {
    Data_pq<Type> *pointer = first;
    Data_pq<Type> *temp = nullptr;

    while (pointer != nullptr) {
        temp = pointer->return_p_next_data();
        delete pointer;
        pointer = temp;
    }
}

// Add an element to the priority queue with a specified priority
template <typename Type>
void Priority_queue<Type>::push(Type new_data, int new_priority) {
    Data_pq<Type> *new_node = new Data_pq<Type>(new_data, new_priority);

    if (first == nullptr || new_priority > first->return_priority()) {
        new_node->set_p_next_data(first);
        first = new_node;
    } else {
        Data_pq<Type> *current = first;
        while (current->return_p_next_data() != nullptr && current->return_p_next_data()->return_priority() >= new_priority) {
            current = current->return_p_next_data();
        }
        new_node->set_p_next_data(current->return_p_next_data());
        current->set_p_next_data(new_node);
    }
}

// Remove the element with the highest priority from the priority queue
template <typename Type>
void Priority_queue<Type>::pop() {
    if (first != nullptr) {
        Data_pq<Type> *temp = first;
        first = first->return_p_next_data();
        delete temp;
    }
}

// Retrieve the element with the highest priority without removing it from the priority queue
template <typename Type>
Type Priority_queue<Type>::top() {
    if (first != nullptr) {
        return first->return_data();
    }
    throw std::out_of_range("Priority queue is empty");
}

// Check if the priority queue is empty
template <typename Type>
bool Priority_queue<Type>::empty() {
    return first == nullptr;
}
