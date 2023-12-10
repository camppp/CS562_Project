void drawCube(float size) {
    float halfSize = size / 2.0f;

    // Draw the front face
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);  // Red
    glVertex3f(-halfSize, -halfSize, halfSize);
    glVertex3f(halfSize, -halfSize, halfSize);
    glVertex3f(halfSize, halfSize, halfSize);
    glVertex3f(-halfSize, halfSize, halfSize);
    glEnd();

    // Draw the back face
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);  // Green
    glVertex3f(-halfSize, -halfSize, -halfSize);
    glVertex3f(halfSize, -halfSize, -halfSize);
    glVertex3f(halfSize, halfSize, -halfSize);
    glVertex3f(-halfSize, halfSize, -halfSize);
    glEnd();

    // Draw the top face
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);  // Blue
    glVertex3f(-halfSize, halfSize, halfSize);
    glVertex3f(halfSize, halfSize, halfSize);
    glVertex3f(halfSize, halfSize, -halfSize);
    glVertex3f(-halfSize, halfSize, -halfSize);
    glEnd();

    // Draw the bottom face
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);  // Yellow
    glVertex3f(-halfSize, -halfSize, halfSize);
    glVertex3f(halfSize, -halfSize, halfSize);
    glVertex3f(halfSize, -halfSize, -halfSize);
    glVertex3f(-halfSize, -halfSize, -halfSize);
    glEnd();

    // Draw the left face
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 1.0f);  // Magenta
    glVertex3f(-halfSize, -halfSize, halfSize);
    glVertex3f(-halfSize, halfSize, halfSize);
    glVertex3f(-halfSize, halfSize, -halfSize);
    glVertex3f(-halfSize, -halfSize, -halfSize);
    glEnd();

    // Draw the right face
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0f);  // Cyan
    glVertex3f(halfSize, -halfSize, halfSize);
    glVertex3f(halfSize, halfSize, halfSize);
    glVertex3f(halfSize, halfSize, -halfSize);
    glVertex3f(halfSize, -halfSize, -halfSize);
    glEnd();
}
