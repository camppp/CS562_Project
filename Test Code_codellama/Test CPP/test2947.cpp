def create_sparse_matrix(entries, columns):
    # Check that the input lists have the same length
    if len(entries) != len(columns):
        raise ValueError("The input lists must have the same length")

    # Create an empty 2D list to represent the sparse matrix
    sparse_matrix = [[0] * len(columns) for _ in range(len(entries))]

    # Loop through the non-zero entries and their corresponding columns
    for i, (entry, column) in enumerate(zip(entries, columns)):
        # Set the non-zero entry in the sparse matrix
        sparse_matrix[i][column] = entry

    return sparse_matrix
