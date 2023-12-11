class Stack:
    class Node:
        def __init__(self, value):
            self.value = value
            self.next = None

    def __init__(self):
        self.head = None
        self.size = 0

    def push(self, value):
        node = Node(value)
        node.next = self.head
        self.head = node
        self.size += 1

    def pop(self):
        if self.size == 0:
            return None
        node = self.head
        self.head = node.next
        self.size -= 1
        return node.value

    def peek(self):
        if self.size == 0:
            return None
        return self.head.value

    def is_empty(self):
        return self.size == 0