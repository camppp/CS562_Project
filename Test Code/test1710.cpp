#include <adf_library.h>
#include <vector>

std::vector<adf_id_t> retrieveDeviceIDs() {
  drm_format_t format;

  // Assume the condition for setting the format variable is known and handled elsewhere

  if (/* condition */) {
    format = DRM_FORMAT_RGB565;
  }

  adf_id_t* dev_ids = nullptr;
  ssize_t n_dev_ids = adf_devices(&dev_ids);

  if (n_dev_ids <= 0) {
    return std::vector<adf_id_t>();  // Return an empty vector if no device IDs are found
  }

  // Convert the array of device IDs to a vector for easier manipulation
  std::vector<adf_id_t> device_ids(dev_ids, dev_ids + n_dev_ids);

  // Free the memory allocated by adf_devices
  adf_free(dev_ids);

  return device_ids;
}
