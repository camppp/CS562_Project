bool PSS_ProcessPropertiesBP::SetValue(const int propId, const char* pValue) {
    if (!pValue) {
        std::cout << "Error: pValue is null." << std::endl;
        return false;
    }

    // Assuming propId corresponds to an array of properties
    if (propId >= 0 && propId < numProperties) {
        // Assuming properties is an array of strings
        properties[propId] = pValue;
        std::cout << "Property " << propId << " set to: " << pValue << std::endl;
        return true;
    } else {
        std::cout << "Error: Invalid propId." << std::endl;
        return false;
    }
}
