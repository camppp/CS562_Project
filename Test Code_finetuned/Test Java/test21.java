class Stack:
    def __init__(self):
        self.stack = []

    def push(self, val):
        self.stack.append(val)

    def pop(self):
        if not self.isEmpty():
            return self.stack.pop()
        else:
            return "Stack is empty"

    def peek(self):
        if not self.isEmpty():
            return self.stack[-1]
        else:
            return "Stack is empty"

    def isEmpty(self):
        return len(self.stack) == 0