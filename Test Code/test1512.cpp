python
from typing import Union

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

def remove_last_element(head: Node) -> Union[int, None]:
    if head is None:  # If the linked list is empty
        return None

    if head.next is None:  # If the linked list has only one element
        removed_element = head.value
        head = None
        return removed_element

    current = head
    while current.next.next:  # Traverse to the second last node
        current = current.next

    removed_element = current.next.value
    current.next = None  # Remove the last node
    return removed_element
