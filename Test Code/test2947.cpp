python
def create_sparse_matrix(entries, columns):
    """
    Create a sparse matrix from the given non-zero entries and their corresponding columns.

    Args:
    entries: A list of non-zero entries in the matrix.
    columns: The column of each non-zero entry (must be of length at least the number of non-zero entries).

    Returns:
    A 2D list representing the sparse matrix.
    """
    num_columns = max(columns)
    sparse_matrix = [[0] * num_columns for _ in range(len(entries))]
    for i in range(len(entries)):
        sparse_matrix[i][columns[i] - 1] = entries[i]
    return sparse_matrix
