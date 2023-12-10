python
from typing import List

def extractFileExtensions(filePaths: List[str]) -> List[str]:
    fileExtensions = []
    for path in filePaths:
        if '.' in path:
            fileExtensions.append(path.split('.')[-1])
        else:
            fileExtensions.append('')
    return fileExtensions
