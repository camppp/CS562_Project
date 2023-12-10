struct ListNode *findLastNodeWithValue(struct ListNode *head, int value) {
    struct ListNode *result = NULL;
    struct ListNode *current = head;
    
    while (current != NULL) {
        if (current->val == value) {
            result = current;
        }
        current = current->next;
    }
    
    return result;
}
