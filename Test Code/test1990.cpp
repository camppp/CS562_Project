python
class FibonacciFunctor:
    def __init__(self):
        self.prev, self.curr = 0, 1

    def __call__(self):
        result = self.prev
        self.prev, self.curr = self.curr, self.prev + self.curr
        return result
