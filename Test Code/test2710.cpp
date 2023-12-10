ListNode* reverseLinkedListInRange(ListNode* head, int left, int right) {
    if (left == right) {
        return head;
    }

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    for (int i = 0; i < left - 1; i++) {
        prev = prev->next;
    }

    ListNode* curr = prev->next;
    ListNode* next = curr->next;

    for (int i = 0; i < right - left; i++) {
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
        next = curr->next;
    }

    head = dummy->next;
    delete dummy;
    return head;
}
