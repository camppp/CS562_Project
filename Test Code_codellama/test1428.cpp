void Begin2D(bool clear)
{
    // Initialize the 2D rendering context
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 0, 0, 0, 0, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Clear the screen if requested
    if (clear)
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
}

void Swap()
{
    // Swap the front and back buffers
    glfwSwapBuffers(window);
}
