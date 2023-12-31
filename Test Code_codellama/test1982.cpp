class Counter:
    def __init__(self, initial_count):
        self.count = initial_count

    def increment(self):
        self.count += 1

    def decrement(self):
        self.count -= 1

    def get_count(self):
        return self.count
