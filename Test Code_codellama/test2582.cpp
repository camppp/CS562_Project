int calculateBatteryPercentage(int currentBatteryLevel) {
    int remainingBatteryPercentage = (currentBatteryLevel / BASE_POWER) * 100;
    return remainingBatteryPercentage;
}
