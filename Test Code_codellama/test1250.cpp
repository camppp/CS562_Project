void toggleControlsWindow(CEGUI::Window* controlsWindow)
{
    // Check if the controls window is currently visible
    if (controlsWindow->isVisible())
    {
        // Make the controls window invisible
        controlsWindow->setVisible(false);
    }
    else
    {
        // Make the controls window visible
        controlsWindow->setVisible(true);
    }

    // Return the new visibility state of the controls window
    return controlsWindow->isVisible();
}
