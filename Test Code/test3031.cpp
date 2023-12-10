void display() {
    Node* current = head;
    while (current != nullptr) {
        current->display(); // Accessing the display method of the current node using the arrow operator
        current = current->next;
    }
}
