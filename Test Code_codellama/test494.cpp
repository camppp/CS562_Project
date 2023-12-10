#include <misaxx/ome/caches/misa_ome_tiff_cache.h>
#include <misaxx/ome/attachments/misa_ome_planes_location.h>
#include <misaxx/core/runtime/misa_parameter_registry.h>

double calculateAverageIntensity(const misaxx::ome::misa_ome_tiff_cache &cache, int plane_index) {
    // Retrieve the planes location from the cache
    const misaxx::ome::misa_ome_planes_location &planes_location = cache.get_attachment<misaxx::ome::misa_ome_planes_location>();

    // Calculate the average intensity of the pixels in the specified plane
    double average_intensity = 0;
    for (const auto &plane : planes_location.get_planes()) {
        if (plane.get_index() == plane_index) {
            for (const auto &pixel : plane.get_pixels()) {
                average_intensity += pixel.get_intensity();
            }
            average_intensity /= plane.get_pixels().size();
            break;
        }
    }

    return average_intensity;
}
