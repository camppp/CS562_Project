int OnHotKey::UnregisterHotkey(VK key, VK modifier) {
    auto it = std::find_if(OnHotKeyHandlers.begin(), OnHotKeyHandlers.end(),
                           [key, modifier](const auto& tuple) {
                               return std::get<1>(tuple) == key && std::get<2>(tuple) == modifier;
                           });
    if (it != OnHotKeyHandlers.end()) {
        OnHotKeyHandlers.erase(it);
        return 1;  // Successfully unregistered hotkey
    }
    return 0;  // Hotkey not found
}

void OnHotKey::HandleHotkeyPress(VK key, VK modifier) {
    for (const auto& handler : OnHotKeyHandlers) {
        if (std::get<1>(handler) == key && std::get<2>(handler) == modifier) {
            std::get<0>(handler)();  // Execute the associated function
            return;
        }
    }
    // Handle not found
}
