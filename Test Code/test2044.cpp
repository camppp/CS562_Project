import numpy as np

def elementwise_add(input1, input2):
    # Validate input shapes
    if input1.shape != input2.shape:
        raise ValueError("Input shapes must match")

    # Perform element-wise addition
    result = np.add(input1, input2)

    return result
