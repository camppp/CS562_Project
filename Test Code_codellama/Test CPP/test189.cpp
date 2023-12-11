ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* current = head;
    ListNode* previous = nullptr;
    int count = 0;

    // Find the nth node from the end of the list
    while (current != nullptr) {
        if (count == n - 1) {
            previous = current;
        }
        current = current->next;
        count++;
    }

    // Remove the nth node from the end of the list
    if (previous != nullptr) {
        previous->next = current->next;
        delete current;
    }

    return head;
}
