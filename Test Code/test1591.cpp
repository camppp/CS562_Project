static bool is_qca1530(void)
{
    static const char qca1530_property_name[] = "sys.qca1530";
    // Assume the existence of a function to query the system for the value of the property name
    // For example, a hypothetical function getPropertyValue(const char* propertyName) is used here

    const char* propertyValue = getPropertyValue(qca1530_property_name);

    if (propertyValue == NULL) {
        // Property not found, QCA1530 is not available
        return false;
    } else if (strcmp(propertyValue, "detect") == 0) {
        // Wait for SoC detection to finish
        // Assume the existence of a function to wait for SoC detection
        // For example, a hypothetical function waitForSoCDetection() is used here
        waitForSoCDetection();
        // After detection, query the property value again
        propertyValue = getPropertyValue(qca1530_property_name);
        if (propertyValue == NULL || strcmp(propertyValue, "no") == 0) {
            return false;
        } else {
            return true;
        }
    } else if (strcmp(propertyValue, "no") == 0) {
        return false;
    } else {
        return true;
    }
}
