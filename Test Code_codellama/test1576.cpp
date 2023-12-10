c
struct ListNode *findLastNodeWithValue(struct ListNode *head, int value) {
    struct ListNode *current = head;
    struct ListNode *last = NULL;

    while (current != NULL) {
        if (current->val == value) {
            last = current;
        }
        current = current->next;
    }

    return last;
}
