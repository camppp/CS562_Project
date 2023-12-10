void HandleKeyEvent(Key key, bool released, EnumSet<KeyModFlags>& currentModifiers) {
    if (key == Key::RightGui) {
        currentModifiers = sl::EnumSetFlagState(currentModifiers, KeyModFlags::RightGui, released);
    }
}
