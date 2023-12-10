void toggleControlsWindow(CEGUI::Window* controlsWindow) {
    bool isVisible = controlsWindow->isVisible();
    controlsWindow->setVisible(!isVisible);
}

// Example usage
// CEGUI::Window *controlsWindow = winMgr.loadWindowLayout("ControlsWindow.layout");
// guiRoot->addChildWindow(controlsWindow);
// controlsWindow->setVisible(false);
// toggleControlsWindow(controlsWindow); // Makes controlsWindow visible
// toggleControlsWindow(controlsWindow); // Makes controlsWindow invisible
