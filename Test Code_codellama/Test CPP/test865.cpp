int OnHotKey::UnregisterHotkey(VK key, VK modifier) {
    for (auto it = OnHotKeyHandlers.begin(); it != OnHotKeyHandlers.end(); ++it) {
        if (std::get<1>(*it) == key && std::get<2>(*it) == modifier) {
            OnHotKeyHandlers.erase(it);
            return 0;
        }
    }
    return -1;
}

void OnHotKey::HandleHotkeyPress(VK key, VK modifier) {
    for (auto it = OnHotKeyHandlers.begin(); it != OnHotKeyHandlers.end(); ++it) {
        if (std::get<1>(*it) == key && std::get<2>(*it) == modifier) {
            std::get<0>(*it)();
            return;
        }
    }
}
