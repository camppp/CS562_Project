int32_t TransportationCreditManager::acquire_credit(inbound_path* path, int32_t desired) {
    // Check if the desired amount of credit is greater than the maximum amount of credit that can be acquired for the given inbound path
    if (desired > driver_.get_max_credit(path)) {
        return -1;  // Error code indicating that the desired amount of credit is not available
    }

    // Check if the desired amount of credit is less than or equal to the minimum amount of credit that can be acquired for the given inbound path
    if (desired <= driver_.get_min_credit(path)) {
        return driver_.get_min_credit(path);
    }

    // Calculate the actual amount of credit that can be acquired based on the driver's credit acquisition logic
    int32_t actual_credit = driver_.acquire_credit(path, desired);

    // Return the actual amount of credit that was acquired
    return actual_credit;
}
