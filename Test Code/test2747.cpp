def minButtonPress(targetVolume: int) -> int:
    volume = 50
    buttonPresses = 0
    while volume < targetVolume:
        if volume + 2 > targetVolume:
            buttonPresses += 1
            volume += 2
        else:
            buttonPresses += 2
            volume += 4
    return buttonPresses
