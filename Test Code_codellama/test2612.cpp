ListNode* reverseList(ListNode* head) {
    ListNode* current = head;
    ListNode* previous = nullptr;

    while (current != nullptr) {
        ListNode* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}
