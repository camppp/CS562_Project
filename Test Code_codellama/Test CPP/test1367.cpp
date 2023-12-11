def processImageList(imageList: List[str]) -> List[str]:
    processedList = []
    for filename in imageList:
        if filename == "":
            continue
        # Perform specific operation on filename
        processedFilename = performOperation(filename)
        processedList.append(processedFilename)
    return processedList
