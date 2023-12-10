template <typename T>
class Stack {
public:
    // Constructor to initialize the stack
    Stack() {
        // Initialize the stack with an empty vector
        stack = std::vector<T>();
    }

    // Add an element to the top of the stack
    void push(const T& element) {
        // Push the element onto the stack
        stack.push_back(element);
    }

    // Remove the element from the top of the stack
    void pop() {
        // Check if the stack is empty
        if (stack.empty()) {
            // Throw an exception if the stack is empty
            throw std::runtime_error("Stack is empty");
        }

        // Pop the top element from the stack
        stack.pop_back();
    }

    // Return the element at the top of the stack without removing it
    T top() const {
        // Check if the stack is empty
        if (stack.empty()) {
            // Throw an exception if the stack is empty
            throw std::runtime_error("Stack is empty");
        }

        // Return the top element of the stack
        return stack.back();
    }

    // Return true if the stack is empty, false otherwise
    bool empty() const {
        // Return true if the stack is empty, false otherwise
        return stack.empty();
    }

private:
    // The stack data structure
    std::vector<T> stack;
};
