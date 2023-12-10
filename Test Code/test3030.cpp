python
def merge180Image(isl180, isr180):
    complete_image = isl180 + isr180[::-1]  # Merge the arrays by concatenating the left side with the reversed right side
    return complete_image
