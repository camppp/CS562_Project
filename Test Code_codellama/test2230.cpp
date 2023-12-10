def extractFunctionNames(sourceCode: str) -> List[str]:
    functionNames = []
    for line in sourceCode.splitlines():
        if line.startswith("function"):
            functionName = line.split("(")[0]
            functionNames.append(functionName)
    return functionNames
