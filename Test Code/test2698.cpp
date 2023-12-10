class WithOptionEmpty:
    def __init__(self, value=None):
        self.value = value

    def is_empty(self):
        return self.value is None

    def get_value(self, default=None):
        if self.is_empty():
            return default
        else:
            return self.value

    def map(self, func):
        if self.is_empty():
            return WithOptionEmpty()
        else:
            return WithOptionEmpty(func(self.value))
