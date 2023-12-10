if (size.getY() > 0) {
    glNormal3f(0.0F, size.getY() + 2, 0.0F);
    glTexCoord2f(0, timesY);
    glVertex3f(position.getX(), position.getY() + size.getY(), position.getZ() + size.getZ());
    glTexCoord2f(0, 0);
    glVertex3f(position.getX(), position.getY() + size.getY(), position.getZ());
    glTexCoord2f(timesX, 0);
    glVertex3f(position.getX() + size.getX(), position.getY() + size.getY(), position.getZ());
    glTexCoord2f(timesX, timesY);
    glVertex3f(position.getX() + size.getX(), position.getY() + size.getY(), position.getZ() + size.getZ());
    glEnd();
} else if (size.getY() < 0) {
    glNormal3f(0.0F, size.getY() + 2, 0.0F);
    glTexCoord2f(0, 0);
    glVertex3f(position.getX(), position.getY(), position.getZ());
    glTexCoord2f(0, timesZ);
    glVertex3f(position.getX(), position.getY(), position.getZ() + size.getZ());
    glTexCoord2f(timesX, timesZ);
    glVertex3f(position.getX() + size.getX(), position.getY(), position.getZ() + size.getZ());
    glEnd();
}
