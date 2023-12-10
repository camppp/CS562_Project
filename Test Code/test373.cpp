__device__ bool isPrefixMatch(uint8_t* destAddr, uint8_t* prefix, int prefixLength) {
    for (int i = 0; i < prefixLength / 8; i++) {
        if (destAddr[i] != prefix[i]) {
            return false;
        }
    }
    int remainingBits = prefixLength % 8;
    if (remainingBits > 0) {
        uint8_t mask = (0xFF << (8 - remainingBits)) & 0xFF;
        if ((destAddr[prefixLength / 8] & mask) != (prefix[prefixLength / 8] & mask)) {
            return false;
        }
    }
    return true;
}

__global__ void ipv6_route_lookup_cuda_kernel(uint8_t* destAddrs, int numDestAddrs, uint8_t* prefixes, uint8_t* nextHops, int numPrefixes) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    if (tid < numDestAddrs) {
        for (int i = 0; i < numPrefixes; i++) {
            uint8_t* prefix = &prefixes[i * 16];
            int prefixLength = prefixes[i * 16 + 16];
            if (isPrefixMatch(&destAddrs[tid * 16], prefix, prefixLength)) {
                // Match found, store the next hop for the destination address
                nextHops[tid] = nextHops[i];
                return;
            }
        }
        // No match found, set next hop to default or invalid value
        nextHops[tid] = 0xFF;
    }
}

extern "C" void ipv6_route_lookup_get_cuda_kernel(uint8_t* destAddrs, int numDestAddrs, uint8_t* prefixes, uint8_t* nextHops, int numPrefixes) {
    // Allocate device memory for input and output arrays
    uint8_t* devDestAddrs;
    uint8_t* devPrefixes;
    uint8_t* devNextHops;
    cudaMalloc((void**)&devDestAddrs, numDestAddrs * 16 * sizeof(uint8_t));
    cudaMalloc((void**)&devPrefixes, numPrefixes * 17 * sizeof(uint8_t));
    cudaMalloc((void**)&devNextHops, numDestAddrs * sizeof(uint8_t));

    // Copy input arrays from host to device
    cudaMemcpy(devDestAddrs, destAddrs, numDestAddrs * 16 * sizeof(uint8_t), cudaMemcpyHostToDevice);
    cudaMemcpy(devPrefixes, prefixes, numPrefixes * 17 * sizeof(uint8_t), cudaMemcpyHostToDevice);

    // Launch the CUDA kernel
    int blockSize = 256;
    int numBlocks = (numDestAddrs + blockSize - 1) / blockSize;
    ipv6_route_lookup_cuda_kernel<<<numBlocks, blockSize>>>(devDestAddrs, numDestAddrs, devPrefixes, devNextHops, numPrefixes);

    // Copy the result array from device to host
    cudaMemcpy(nextHops, devNextHops, numDestAddrs * sizeof(uint8_t), cudaMemcpyDeviceToHost);

    // Free device memory
    cudaFree(devDestAddrs);
    cudaFree(devPrefixes);
    cudaFree(devNextHops);
}
