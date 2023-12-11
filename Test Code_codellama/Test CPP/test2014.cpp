def updatePlayerPosition(inputFlags: int, position: Vector2, cameraLookDirection: Vector2, playerSpeed: float, modifier: float) -> Vector2:
    # Handle input flags for moving backward
    if inputFlags & InputBackward:
        position -= cameraLookDirection * playerSpeed * modifier

    # Handle input flags for moving left
    if inputFlags & InputLeft:
        position -= Vector2(cameraLookDirection.y, -cameraLookDirection.x) * playerSpeed * modifier

    # Handle input flags for moving right
    if inputFlags & InputRight:
        position += Vector2(cameraLookDirection.y, -cameraLookDirection.x) * playerSpeed * modifier

    return position
