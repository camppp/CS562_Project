python
def convertString(inputStr):
    if len(inputStr) < 2:
        return inputStr.upper()
    else:
        return (inputStr[0] + inputStr[-1]).upper()
