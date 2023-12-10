c
void push(Node* &top, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop(Node* &top) {
    Node* temp = top;
    top = top->next;
    delete temp;
}

int top(Node* top) {
    return top->data;
}

int getMin(Node* top) {
    int min = top->data;
    while (top != NULL) {
        if (top->data < min) {
            min = top->data;
        }
        top = top->next;
    }
    return min;
}
