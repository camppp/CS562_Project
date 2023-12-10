#include <adf.h>

// Function to retrieve device IDs using the ADF library
std::vector<std::string> get_device_ids() {
    // Set the format to DRM_FORMAT_RGB565 if a certain condition is met
    if (condition) {
        format = DRM_FORMAT_RGB565;
    }

    // Retrieve device IDs using the adf_devices function
    std::vector<std::string> device_ids;
    adf_devices(format, &device_ids);

    // Return the list of device IDs
    return device_ids;
}
