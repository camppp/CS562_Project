bool enableMotionPlus(wiimote_state& remote) {
    if (remote.ExtensionType == wiimote_state::NONE) {
        bool res = remote.EnableMotionPlus();
        return res;
    }
    return false;  // Motion plus feature is already enabled or enabling it failed
}
