void DrawSpriteRotozoom(VertexBuffer vertexBuffer, int xpos, int ypos, int pivotX, int pivotY, float sprX, float sprY, int width, int height, VertexBuffer vertexC, UVCoordinates uvC, int spriteSheetID) {
    // Calculate the center of the sprite
    int centerX = xpos + pivotX;
    int centerY = ypos + pivotY;

    // Apply rotozoom effect
    for (int i = 0; i < vertexBuffer.size(); i++) {
        // Translate the vertex to the origin
        int translatedX = vertexBuffer[i].x - centerX;
        int translatedY = vertexBuffer[i].y - centerY;

        // Apply rotation
        int rotatedX = translatedX * cos(angle) - translatedY * sin(angle);
        int rotatedY = translatedX * sin(angle) + translatedY * cos(angle);

        // Apply scaling
        int scaledX = rotatedX * sprX;
        int scaledY = rotatedY * sprY;

        // Translate the vertex back to its original position
        int finalX = scaledX + centerX;
        int finalY = scaledY + centerY;

        // Draw the vertex at its final position
        drawVertex(finalX, finalY, uvC[i].u, uvC[i].v, spriteSheetID);
    }
}
