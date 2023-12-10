python
from typing import Tuple

class Vector2:
    def __init__(self, x: float, y: float):
        self.x = x
        self.y = y

def updatePlayerPosition(inputFlags: int, position: Vector2, cameraLookDirection: Vector2, playerSpeed: float, modifier: float) -> Vector2:
    if inputFlags & InputForward:
        position += cameraLookDirection * playerSpeed * modifier
    if inputFlags & InputBackward:
        position -= cameraLookDirection * playerSpeed * modifier
    # Assuming cameraLookDirection is normalized
    rightDirection = Vector2(cameraLookDirection.y, -cameraLookDirection.x)
    if inputFlags & InputLeft:
        position -= rightDirection * playerSpeed * modifier
    if inputFlags & InputRight:
        position += rightDirection * playerSpeed * modifier
    return position
