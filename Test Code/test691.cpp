python
class Counter:
    def __init__(self):
        self.value = 0

    def increment(self):
        self.value += 1

    def decrement(self):
        self.value -= 1

    def reset(self):
        self.value = 0

    def get_value(self):
        return self.value

# Example usage
counter = Counter()
print(counter.get_value())  # Output: 0
counter.increment()
print(counter.get_value())  # Output: 1
counter.decrement()
print(counter.get_value())  # Output: 0
counter.reset()
print(counter.get_value())  # Output: 0
