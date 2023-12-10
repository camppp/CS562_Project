void renderEye(const ovrPosef& eyePose, const ovrTexture& eyeTexture) {
    // Set the viewport to the size of the eye texture
    glViewport(0, 0, eyeTexture.Width, eyeTexture.Height);

    // Set the projection matrix for the eye
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, (float)eyeTexture.Width / (float)eyeTexture.Height, 0.1, 100);

    // Set the modelview matrix for the eye
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyePose.Position.x, eyePose.Position.y, eyePose.Position.z,
              eyePose.Orientation.x, eyePose.Orientation.y, eyePose.Orientation.z,
              0, 1, 0);

    // Draw the scene for the eye
    // ...

    // Swap the buffers for the eye
    glutSwapBuffers();
}
