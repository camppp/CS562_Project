public String computeValueBasedOnTimezone(String timezone) {
    if (cachedTimezone == null || !cachedTimezone.equals(timezone)) {
        // Compute the value based on the current timezone
        cachedValue = computeValue(timezone);
        cachedTimezone = timezone;
    }
    return cachedValue;
}
