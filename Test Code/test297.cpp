void Stack::push(int val) {
    Node* newNode = new Node(val);
    newNode->next = top;
    top = newNode;
}

void Stack::pop() {
    if (top == nullptr) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

int Stack::peek() {
    if (top == nullptr) {
        std::cout << "Stack is empty" << std::endl;
        return -1;
    }
    return top->data;
}

bool Stack::isEmpty() {
    return top == nullptr;
}
