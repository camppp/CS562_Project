#include <iostream>

struct Data {
    // Define the structure of the Data object
};

struct FrameGraphPassResources {
    // Define the structure of the FrameGraphPassResources object
};

void BlurData(const Data &data, FrameGraphPassResources &resources, void *ctx) {
    // Apply the blur effect to the input data using the provided resources and context
    // Ensure that the blur effect is applied within the GPU zone and the named debug marker

    // Example implementation:
    // Start the named debug marker
    NAMED_DEBUG_MARKER(name);

    // Start the Tracy GPU zone for blur
    TracyGpuZone("Blur");

    // Apply the blur effect using the provided resources and context
    // Example: 
    // Apply blur effect using resources and context

    // End the Tracy GPU zone for blur
    TracyGpuZoneEnd();
}
