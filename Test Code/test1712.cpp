python
def mergeData(data1, data2, identifier):
    mergedData = {}
    for key, value in data1.items():
        mergedData[key] = value
    for key, value in data2.items():
        if key != identifier:
            mergedData[key] = value
    return mergedData
