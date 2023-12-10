python
def getNextFocus(currentFocus: str) -> str:
    if currentFocus == "mHullNumberSelector":
        return "mServerIpSelector"
    elif currentFocus == "mServerIpSelector":
        return "mConnectButton"
    elif currentFocus == "mConnectButton":
        return "mHullNumberSelector"
    else:
        raise ValueError("Invalid currentFocus value")
