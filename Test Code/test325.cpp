void manipulateLinkedList(stack<Node*>& c) {
    Node* tail = nullptr;
    while (!c.empty()) {
        Node* tmp = c.top();
        if (tail != nullptr) {
            tmp->next = tail;
            tail = tmp;
        }
        c.pop();
        if (tmp->next != nullptr) {
            c.push(tmp->next);
        }
    }
}
