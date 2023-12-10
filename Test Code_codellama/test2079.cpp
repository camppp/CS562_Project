bool enableMotionPlus(wiimote_state& remote)
{
    // Check if the current extension type is NONE
    if (remote.ExtensionType != NONE)
    {
        // The motion plus feature is already enabled or the extension type is not NONE
        return false;
    }

    // Enable the motion plus feature
    remote.ExtensionType = MOTION_PLUS;

    // Return true if the motion plus feature was enabled successfully
    return true;
}
