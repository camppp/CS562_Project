template <typename T>
ListNode<T>* reverseList(ListNode<T>* head) {
    ListNode<T>* prev = nullptr;
    ListNode<T>* curr = head;
    ListNode<T>* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
