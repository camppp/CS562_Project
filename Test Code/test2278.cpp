void push(const T& value) {
    Node* newNode = new Node(value, topNode);
    topNode = newNode;
}

void pop() {
    if (topNode != nullptr) {
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
}

T top() const {
    if (topNode != nullptr) {
        return topNode->data;
    }
    throw std::out_of_range("Stack is empty");
}

bool empty() const {
    return topNode == nullptr;
}
