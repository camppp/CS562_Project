void HandleKeyEvent(Key key, bool released, EnumSet<KeyModFlags>& currentModifiers) {
    // Update the currentModifiers enum set based on the provided key and released state
    if (key == Key::RightGui) {
        // Update the RightGui flag in the currentModifiers enum set
        sl::EnumSetFlagState(currentModifiers, KeyModFlags::RightGui, released);
    } else if (key == Key::Shift || key == Key::Ctrl || key == Key::Alt) {
        // Update the corresponding modifier flag in the currentModifiers enum set
        sl::EnumSetFlagState(currentModifiers, key, released);
    }
}
