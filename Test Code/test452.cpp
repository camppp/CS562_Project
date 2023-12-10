bool ManagePowerSaving(Logger& logger_, std::chrono::microseconds kSettingSleep) {
    if (!SetWakeupOption()) {
        logger_.LogError("failed to set wakeup option");
        return false;
    }
    delayMicroseconds(kSettingSleep.count());

    if (esp_light_sleep_start() != ESP_OK) {
        logger_.LogError("failed to start light sleep");
        return false;
    }
    return true;
}
