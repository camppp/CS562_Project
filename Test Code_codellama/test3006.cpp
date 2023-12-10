void DrawSpriteRotozoom(const VertexBuffer& vertexBuffer, const float xpos, const float ypos, const float pivotX, const float pivotY, const float sprX, const float sprY, const float width, const float height, const int spriteSheetID) {
    // Calculate the rotation matrix
    const float cosRot = cosf(pivotX * M_PI / 180.0f);
    const float sinRot = sinf(pivotY * M_PI / 180.0f);
    const float rotMatrix[4][4] = {
        {cosRot, -sinRot, 0.0f, 0.0f},
        {sinRot, cosRot, 0.0f, 0.0f},
        {0.0f, 0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 1.0f}
    };

    // Calculate the zoom matrix
    const float zoomMatrix[4][4] = {
        {sprX, 0.0f, 0.0f, 0.0f},
        {0.0f, sprY, 0.0f, 0.0f},
        {0.0f, 0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 1.0f}
    };

    // Calculate the final matrix
    const float finalMatrix[4][4] = {
        {rotMatrix[0][0] * zoomMatrix[0][0] + rotMatrix[0][1] * zoomMatrix[1][0], rotMatrix[0][0] * zoomMatrix[0][1] + rotMatrix[0][1] * zoomMatrix[1][1], 0.0f, 0.0f},
        {rotMatrix[1][0] * zoomMatrix[0][0] + rotMatrix[1][1] * zoomMatrix[1][0], rotMatrix[1][0] * zoomMatrix[0][1] + rotMatrix[1][1] * zoomMatrix[1][1], 0.0f, 0.0f},
        {0.0f, 0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 1.0f}
    };

    // Draw the sprite
    for (int i = 0; i < 4; i++) {
        const float x = finalMatrix[0][0] * vertexBuffer[i].v.x + finalMatrix[0][1] * vertexBuffer[i].v.y + finalMatrix[0][2] * vertexBuffer[i].v.z + finalMatrix[0][3] * vertexBuffer[i].v.w;
        const float y = finalMatrix[1][0] * vertexBuffer[i].v.x + finalMatrix[1][1] * vertexBuffer[i].v.y + finalMatrix[1][2] * vertexBuffer[i].v.z + finalMatrix[1][3] * vertexBuffer[i].v.w;
        const float u = finalMatrix[2][0] * vertexBuffer[i].u.x + finalMatrix[2][1] * vertexBuffer[i].u.y + finalMatrix[2][2] * vertexBuffer[i].u.z + finalMatrix[2][3] * vertexBuffer[i].u.w;
        const float v = finalMatrix[3][0] * vertexBuffer[i].u.x + finalMatrix[3][1] * vertexBuffer[i].u.y + finalMatrix[3][2] * vertexBuffer[i].u.z + finalMatrix[3][3] * vertexBuffer[i].u.w;
        DrawSprite(xpos + x, ypos + y, u, v, width, height, spriteSheetID);
    }
}
