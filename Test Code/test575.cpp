template <typename T>
class Stack {
private:
    std::vector<T> elements;  // Using std::vector to store elements

public:
    // Constructor to initialize the stack
    Stack() {
        // No additional initialization required as vector is initialized by default
    }

    // Add an element to the top of the stack
    void push(const T& element) {
        elements.push_back(element);
    }

    // Remove the element from the top of the stack
    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        }
    }

    // Return the element at the top of the stack without removing it
    T top() const {
        if (!elements.empty()) {
            return elements.back();
        }
        throw std::out_of_range("Stack is empty");
    }

    // Return true if the stack is empty, false otherwise
    bool empty() const {
        return elements.empty();
    }
};
