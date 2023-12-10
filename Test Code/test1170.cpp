#include <bgfx/bgfx.h>
#include <cstdint>
#include <vector>

bgfx::IndexBufferHandle createIndexBuffer(const std::vector<uint32_t>& indexData) {
    auto indexMem = bgfx::makeRef(indexData.data(), static_cast<uint32_t>(indexData.size() * sizeof(uint32_t)));
    bgfx::IndexBufferHandle indexBuffer = bgfx::createIndexBuffer(indexMem, BGFX_BUFFER_INDEX32);
    return indexBuffer;
}
