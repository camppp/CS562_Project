python
class Memory:
    def __init__(self, data):
        self.data = data

class MemoryCache:
    def __init__(self, size):
        self.size = size
        self.cache = []

    def obtain(self):
        if self.cache:
            return self.cache.pop(0)
        else:
            return Memory(None)

    def evict(self, n):
        self.cache = self.cache[n:]

# Usage
input = MemoryCache(10)
memory = Memory("some_data")
data = "some_data"
input.cache = [Memory(data + str(i)) for i in range(10)]

# Test the implementation
assert input.obtain().data == memory.data
input.evict(5)
assert input.obtain().data == Memory(data + str(5)).data
