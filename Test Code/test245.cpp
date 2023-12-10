python
from typing import List

def calculate_result_shape(lhs_shape: List[int], rhs_shape: List[int]) -> List[int]:
    lhs_dim = len(lhs_shape)
    rhs_dim = len(rhs_shape)
    result_shape = [0] * lhs_dim  # Initialize the resulting shape with zeros

    if rhs_dim == 1 or rhs_dim == lhs_dim:
        for i in range(lhs_dim):
            result_shape[i] = lhs_shape[i]

    return result_shape
