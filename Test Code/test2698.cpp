python
class WithOptionEmpty:
    def __init__(self, value=None):
        self.value = value

    def is_empty(self):
        return self.value is None

    def get_or_default(self, default_value):
        return self.value if not self.is_empty() else default_value

    def map(self, func):
        if not self.is_empty():
            return WithOptionEmpty(func(self.value))
        else:
            return WithOptionEmpty()

# Example usage
opt_empty = WithOptionEmpty(10)
print(opt_empty.is_empty())  # Output: False
print(opt_empty.get_or_default(0))  # Output: 10
mapped_empty = opt_empty.map(lambda x: x * 2)
print(mapped_empty.get_or_default(0))  # Output: 20

empty = WithOptionEmpty()
print(empty.is_empty())  # Output: True
print(empty.get_or_default(0))  # Output: 0
mapped_empty = empty.map(lambda x: x * 2)
print(mapped_empty.is_empty())  # Output: True
