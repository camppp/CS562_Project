void configure_device() {
    set_antenna_switch(RBI_SWITCH_OFF);
    Radio_SMPS_Set(SMPS_DRIVE_SETTING_DEFAULT);
}
