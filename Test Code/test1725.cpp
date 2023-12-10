#include <vulkan/vulkan.hpp>
#include <map>

std::vector<vk::ImageMemoryBarrier> organizeImageMemoryBarriers(
    const std::vector<vk::ImageMemoryBarrier>& ImagePreBarrier,
    const std::vector<vk::ImageMemoryBarrier>& ImagePostBarrier) {
  std::map<vk::Image, std::vector<vk::ImageMemoryBarrier>> barrierMap;

  // Group pre-barriers by image handle
  for (const auto& preBarrier : ImagePreBarrier) {
    barrierMap[preBarrier.image].emplace_back(preBarrier);
  }

  // Group post-barriers by image handle
  for (const auto& postBarrier : ImagePostBarrier) {
    barrierMap[postBarrier.image].emplace_back(postBarrier);
  }

  std::vector<vk::ImageMemoryBarrier> OrganizedBarriers;

  // Process barriers for each image handle
  for (const auto& entry : barrierMap) {
    const auto& image = entry.first;
    const auto& barriers = entry.second;

    // Sort pre-barriers based on subresource range
    std::vector<vk::ImageMemoryBarrier> preBarriers;
    // Sort post-barriers based on subresource range
    std::vector<vk::ImageMemoryBarrier> postBarriers;

    for (const auto& barrier : barriers) {
      if (barrier.srcAccessMask == vk::AccessFlagBits::eMemoryWrite) {
        preBarriers.emplace_back(barrier);
      } else {
        postBarriers.emplace_back(barrier);
      }
    }

    std::sort(preBarriers.begin(), preBarriers.end(), [](const auto& a, const auto& b) {
      return a.subresourceRange.baseMipLevel < b.subresourceRange.baseMipLevel ||
             (a.subresourceRange.baseMipLevel == b.subresourceRange.baseMipLevel &&
              a.subresourceRange.baseArrayLayer < b.subresourceRange.baseArrayLayer);
    });

    std::sort(postBarriers.begin(), postBarriers.end(), [](const auto& a, const auto& b) {
      return a.subresourceRange.baseMipLevel < b.subresourceRange.baseMipLevel ||
             (a.subresourceRange.baseMipLevel == b.subresourceRange.baseMipLevel &&
              a.subresourceRange.baseArrayLayer < b.subresourceRange.baseArrayLayer);
    });

    // Append sorted pre-barriers and post-barriers to the organized list
    OrganizedBarriers.insert(OrganizedBarriers.end(), preBarriers.begin(), preBarriers.end());
    OrganizedBarriers.insert(OrganizedBarriers.end(), postBarriers.begin(), postBarriers.end());
  }

  return OrganizedBarriers;
}
