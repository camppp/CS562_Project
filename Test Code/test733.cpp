void renderObject(const glm::vec3& position, const glm::vec3& size, const glm::vec3& timesX, const glm::vec3& timesY, const glm::vec3& timesZ) {
  // Calculate the scale factors for the object
  float scaleX = size.x / 2.0f;
  float scaleY = size.y / 2.0f;
  float scaleZ = size.z / 2.0f;

  // Calculate the rotation angles for the object
  float angleX = 0.0f;
  float angleY = 0.0f;
  float angleZ = 0.0f;

  // Calculate the translation factors for the object
  float translateX = position.x;
  float translateY = position.y;
  float translateZ = position.z;

  // Set the object's position, scale, and rotation
  glTranslatef(translateX, translateY, translateZ);
  glRotatef(angleX, 1.0f, 0.0f, 0.0f);
  glRotatef(angleY, 0.0f, 1.0f, 0.0f);
  glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
  glScalef(scaleX, scaleY, scaleZ);

  // Set the object's texture coordinates
  glTexCoord2f(timesX.x, timesX.y);
  glTexCoord2f(timesY.x, timesY.y);
  glTexCoord2f(timesZ.x, timesZ.y);

  // Draw the object
  glBegin(GL_QUADS);
  glVertex3f(-scaleX, -scaleY, -scaleZ);
  glVertex3f(scaleX, -scaleY, -scaleZ);
  glVertex3f(scaleX, scaleY, -scaleZ);
  glVertex3f(-scaleX, scaleY, -scaleZ);
  glEnd();

  // If the size in the y-direction is less than 0, render the object flipped
  if (size.y < 0) {
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-scaleX, -scaleY, -scaleZ);
    glVertex3f(scaleX, -scaleY, -scaleZ);
    glVertex3f(scaleX, scaleY, -scaleZ);
    glVertex3f(-scaleX, scaleY, -scaleZ);
    glEnd();
  }
}
