python
import numpy as np
import pybind11 as py

def elementwise_add(input1, input2):
    buf1 = input1.request()
    buf2 = input2.request()

    if buf1.shape != buf2.shape:
        raise ValueError("Input shapes must match")

    result = py.array_t<float>(buf1.size)
    buf3 = result.request()

    ptr1 = buf1.ptr
    ptr2 = buf2.ptr
    ptr3 = buf3.ptr

    for i in range(buf1.shape[0]):
        ptr3[i] = ptr1[i] + ptr2[i]

    return np.array(result)
