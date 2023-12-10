void bind(InputDevice& device, const std::string& group, const std::string& input, const std::string& oldValue, const std::string& newValue) {
    // Reset the active mapping and set the status message in the settings window
    activeMapping = {};
    settingsWindow.setStatusMessage("Mapping assigned.");

    // Trigger a refresh of the mappings
    refreshMappings();

    // Activate a timer that disables itself and cancels the current mapping
    auto timer = std::make_unique<std::thread>([&]() {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        timer->detach();
        cancelMapping();
    });
}
