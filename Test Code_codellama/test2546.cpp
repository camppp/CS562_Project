__global__ void thresholding(uchar4* channels, uchar4* BlobLower) {
    int x = blockIdx.x * blockDim.x + threadIdx.x;
    int y = blockIdx.y * blockDim.y + threadIdx.y;
    int channel = blockIdx.z;

    if (x < channels[channel].width && y < channels[channel].height) {
        uchar4 pixel = channels[channel].data[y * channels[channel].width + x];
        if (pixel.x < BlobLower[channel].x) {
            pixel.x = 0;
        } else {
            pixel.x = 255;
        }
        if (pixel.y < BlobLower[channel].y) {
            pixel.y = 0;
        } else {
            pixel.y = 255;
        }
        if (pixel.z < BlobLower[channel].z) {
            pixel.z = 0;
        } else {
            pixel.z = 255;
        }
        channels[channel].data[y * channels[channel].width + x] = pixel;
    }
}
