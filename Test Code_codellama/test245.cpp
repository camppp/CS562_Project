def calculate_result_shape(lhs_shape, rhs_shape):
    if len(rhs_shape) == 1:
        return lhs_shape
    elif len(rhs_shape) == len(lhs_shape):
        return lhs_shape
    else:
        raise ValueError("Invalid shapes for tensor operation")
