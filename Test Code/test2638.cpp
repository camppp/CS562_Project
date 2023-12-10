python
from typing import Tuple

def infer_backprop_data_shape(input_shape: Tuple[int], in_channels: int, out_channels: int, kernel_size: Tuple[int], stride: Tuple[int], padding: Tuple[int]) -> Tuple[int]:
    # Calculate the spatial dimensions after backpropagation
    h_out = (input_shape[0] - 1) * stride[0] - 2 * padding[0] + kernel_size[0]
    w_out = (input_shape[1] - 1) * stride[1] - 2 * padding[1] + kernel_size[1]
    
    # Return the inferred shape of the input data after backpropagation
    return (h_out, w_out, in_channels)
