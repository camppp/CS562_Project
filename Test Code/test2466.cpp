def formatLogMessage(logMessage: str, _verbose: int) -> str:
    if _verbose > 0:
        return "VERBOSE: " + logMessage
    else:
        return logMessage
