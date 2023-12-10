std::vector<vk::ImageMemoryBarrier> organizeImageMemoryBarriers(
    const std::vector<vk::ImageMemoryBarrier>& ImagePreBarrier,
    const std::vector<vk::ImageMemoryBarrier>& ImagePostBarrier) {
  std::vector<vk::ImageMemoryBarrier> OrganizedBarriers;

  // Group barriers by image handle
  std::map<VkImage, std::vector<vk::ImageMemoryBarrier>> BarrierGroups;
  for (const auto& PreBarrier : ImagePreBarrier) {
    BarrierGroups[PreBarrier.image].push_back(PreBarrier);
  }
  for (const auto& PostBarrier : ImagePostBarrier) {
    BarrierGroups[PostBarrier.image].push_back(PostBarrier);
  }

  // Order barriers within each group
  for (const auto& BarrierGroup : BarrierGroups) {
    std::sort(BarrierGroup.second.begin(), BarrierGroup.second.end(),
              [](const vk::ImageMemoryBarrier& a, const vk::ImageMemoryBarrier& b) {
                if (a.image != b.image) {
                  return a.image < b.image;
                }
                if (a.subresourceRange.baseMipLevel != b.subresourceRange.baseMipLevel) {
                  return a.subresourceRange.baseMipLevel < b.subresourceRange.baseMipLevel;
                }
                if (a.subresourceRange.baseArrayLayer != b.subresourceRange.baseArrayLayer) {
                  return a.subresourceRange.baseArrayLayer < b.subresourceRange.baseArrayLayer;
                }
                return false;
              });
  }

  // Add pre-barriers before post-barriers
  for (const auto& BarrierGroup : BarrierGroups) {
    for (const auto& PreBarrier : BarrierGroup.second) {
      OrganizedBarriers.push_back(PreBarrier);
    }
    for (const auto& PostBarrier : BarrierGroup.second) {
      OrganizedBarriers.push_back(PostBarrier);
    }
  }

  return OrganizedBarriers;
}
