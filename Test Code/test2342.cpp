python
def setTextColor(isPressedDown, highlightColor, borderColor):
    if isPressedDown:
        onLblTextColor = highlightColor
        offLblTextColor = highlightColor
    else:
        onLblTextColor = borderColor
        offLblTextColor = borderColor
    return onLblTextColor, offLblTextColor
