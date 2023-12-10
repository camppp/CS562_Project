python
def calculateColumnIndex(relX, keyXSize):
    relX -= keyXSize / 2  # Subtract half of keyXSize from relX
    col = relX / keyXSize  # Calculate the column index
    if relX < 0:
        col = 0  # Set col to 0 if relX is less than 0
    elif col > 8:
        col = 8  # Set col to 8 if it exceeds 8
    return int(col)  # Return the calculated column index as an integer
