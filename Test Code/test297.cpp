void Stack::push(int val) {
    Node* newNode = new Node(val);
    if (top == nullptr) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
}

void Stack::pop() {
    if (top == nullptr) {
        std::cout << "Stack is empty. Cannot pop." << std::endl;
    } else {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

int Stack::peek() {
    if (top == nullptr) {
        std::cout << "Stack is empty. Cannot peek." << std::endl;
        return -1; // Assuming -1 as an error value
    } else {
        return top->data;
    }
}

bool Stack::isEmpty() {
    return top == nullptr;
}
