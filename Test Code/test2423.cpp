GLFWmonitor* PlatformWindow::GetRiftMonitorByName(const char* name) {
    // Get the list of available monitors
    GLFWmonitor** monitors = glfwGetMonitors(nullptr);

    // Iterate over the list of monitors
    for (int i = 0; i < glfwGetMonitorCount(); i++) {
        // Get the name of the current monitor
        const char* monitorName = glfwGetMonitorName(monitors[i]);

        // Check if the monitor name matches the specified name
        if (strcmp(monitorName, name) == 0) {
            // Return a pointer to the monitor object
            return monitors[i];
        }
    }

    // If no monitor with the specified name is found, return nullptr
    return nullptr;
}
