GLFWmonitor* PlatformWindow::GetRiftMonitorByName(const char* name) {
    int count;
    GLFWmonitor** monitors = glfwGetMonitors(&count);

    for (int i = 0; i < count; i++) {
        const char* monitorName = glfwGetMonitorName(monitors[i]);
        if (monitorName && strcmp(monitorName, name) == 0) {
            return monitors[i];
        }
    }

    return nullptr; // Return nullptr if no monitor with the specified name is found
}
