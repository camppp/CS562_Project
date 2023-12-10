python
def calculateAddress(value, step):
    address = (value / step) - 1
    index = int(address)
    proportion = address - index
    return (index, int(index), proportion)
