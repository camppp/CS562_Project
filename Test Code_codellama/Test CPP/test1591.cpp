bool is_qca1530() {
    // Get the value of the "sys.qca1530" property
    std::string value = get_property("sys.qca1530");

    // Check if the value is "detect"
    if (value == "detect") {
        // Wait for the SoC detection to finish
        wait_for_soc_detection();

        // Get the value of the "sys.qca1530" property again
        value = get_property("sys.qca1530");
    }

    // Check if the value is "true"
    if (value == "true") {
        return true;
    } else {
        return false;
    }
}
