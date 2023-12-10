bool ManagePowerSaving(Logger& logger_, std::chrono::microseconds kSettingSleep) {
    // Set wakeup option
    if (setWakeupOption() != ESP_OK) {
        logger_.LogError("failed to set wakeup option");
        return false;
    }

    // Introduce delay
    delayMicroseconds(kSettingSleep.count());

    // Start light sleep mode
    if (esp_light_sleep_start() != ESP_OK) {
        logger_.LogError("failed to start light sleep");
        return false;
    }

    return true;
}
