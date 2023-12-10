template <typename T>
ListNode<T>* reverseList(ListNode<T>* head)
{
    ListNode<T>* current = head;
    ListNode<T>* previous = nullptr;

    while (current != nullptr)
    {
        ListNode<T>* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}
