#include <misaxx/ome/caches/misa_ome_tiff_cache.h>
#include <misaxx/ome/attachments/misa_ome_planes_location.h>
#include <misaxx/core/runtime/misa_parameter_registry.h>

double calculateAverageIntensity(const misaxx::ome::misa_ome_tiff_cache &cache, int plane_index) {
    // Retrieve the planes location from the cache
    misaxx::ome::misa_ome_planes_location planes_location = cache.get_attachment<misaxx::ome::misa_ome_planes_location>();

    // Check if the plane index is valid
    if (plane_index < 0 || plane_index >= planes_location.size()) {
        throw std::out_of_range("Invalid plane index");
    }

    // Get the pixel data for the specified plane
    const cv::Mat &plane_data = planes_location[plane_index].get_plane();

    // Calculate the average intensity of the pixels in the plane
    double total_intensity = 0.0;
    for (int row = 0; row < plane_data.rows; ++row) {
        for (int col = 0; col < plane_data.cols; ++col) {
            total_intensity += plane_data.at<ushort>(row, col);  // Assuming pixel intensity is stored as ushort
        }
    }

    // Calculate the average intensity
    double average_intensity = total_intensity / (plane_data.rows * plane_data.cols);
    return average_intensity;
}
