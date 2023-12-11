import numpy as np

def calculate_accuracy(pred, real):
    correct = np.sum(pred == real)
    total = len(pred)
    return correct / total

import numpy as np

pred = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
real = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 11])
print(calculate_accuracy(pred, real)) # Output: 0.9