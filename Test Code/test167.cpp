python
class MaxStack:
    def __init__(self):
        self.head = None

    def push(self, value):
        if self.head is None:
            self.head = Node(value, value)
        else:
            new_max = max(value, self.head.max_value)
            new_node = Node(value, new_max)
            new_node.next = self.head
            self.head = new_node

    def pop(self):
        if self.head is None:
            return None
        else:
            value = self.head.value
            self.head = self.head.next
            return value

    def get_max(self):
        if self.head is not None:
            return self.head.max_value
        else:
            return None
