void XPLMEnableFeature(const char *inFeature, int inEnable)
{
    // Check if the feature is already enabled or disabled
    int isEnabled = XPLMGetFeatureState(inFeature);

    // If the feature is already enabled and we want to disable it, or
    // if the feature is already disabled and we want to enable it,
    // then we need to toggle the feature state
    if ((isEnabled && inEnable == 0) || (!isEnabled && inEnable == 1))
    {
        // Toggle the feature state
        XPLMSetFeatureState(inFeature, !isEnabled);
    }
}
