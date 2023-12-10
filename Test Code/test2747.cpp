python
def minButtonPress(targetVolume: int) -> int:
    initialVolume = 50
    buttonPresses = abs(targetVolume - initialVolume) // 2
    return buttonPresses

# Test the function
targetVolume = 54
print(minButtonPress(targetVolume))  # Output: 2
