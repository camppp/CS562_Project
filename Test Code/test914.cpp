def extractFileExtensions(filePaths: List[str]) -> List[str]:
    extensions = []
    for filePath in filePaths:
        dotIndex = filePath.rfind('.')
        if dotIndex != -1:
            extension = filePath[dotIndex+1:]
            extensions.append(extension)
        else:
            extensions.append('')
    return extensions
