void generateMipmaps(TextureImage& texture, VkFormat format, VkExtent3D extent, uint32_t mipLevels) {
    // Transition image layout to transfer destination optimal
    device->transitionImageLayout(texture.mImage.mImage, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, mipLevels);

    // Copy buffer to image
    device->copyBufferToImage(stagingBuffer.mBuffer, texture.mImage.mImage, extent);

    // Generate mipmaps
    device->generateMipmaps(texture.mImage.mImage, format, extent, mipLevels);
}
