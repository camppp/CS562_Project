def most_effective_treatment(matrix, subclone_index):
    # Get the row of the matrix corresponding to the subclone
    subclone_row = matrix[subclone_index]
    
    # Find the maximum value in the row
    max_value = max(subclone_row)
    
    # Find the index of the maximum value in the row
    max_index = subclone_row.index(max_value)
    
    return max_index