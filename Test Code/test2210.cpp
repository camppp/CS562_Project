python
def processResults(reslist):
    if not reslist:
        return []
    else:
        # Remove negative numbers and sort positive numbers
        modified_list = sorted([x for x in reslist if x >= 0])
        return modified_list
