class MaxStack:
    def __init__(self):
        self.head = None
        self.max_value = None

    def push(self, value):
        if self.head is None:
            self.head = Node(value, value)
            self.max_value = value
        else:
            new_max = max(value, self.max_value)
            new_node = Node(value, new_max)
            new_node.next = self.head
            self.head = new_node

    def pop(self):
        if self.head is None:
            return None
        else:
            value = self.head.value
            self.head = self.head.next
            if self.head is None:
                self.max_value = None
            else:
                self.max_value = self.head.max_value
            return value

    def get_max(self):
        return self.max_value
