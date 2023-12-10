c
void configure_device()
{
    // Switch the antenna off
    set_antenna_switch(RBI_SWITCH_OFF);

    // Set the power management system to the default drive setting
    Radio_SMPS_Set(SMPS_DRIVE_SETTING_DEFAULT);
}
