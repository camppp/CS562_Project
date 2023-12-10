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

    // Start the GPU zone and named debug marker
    TracyGpuZone(ctx, "BlurData");

    // Apply the blur effect to the input data
    // ...

    // End the GPU zone and named debug marker
    TracyGpuZoneEnd(ctx);
}
