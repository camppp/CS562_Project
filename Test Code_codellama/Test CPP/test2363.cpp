#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> latencyMeasurements = {100, 200, 300, 400, 500};
    double p95Latency = calculateP95Latency(latencyMeasurements);
    std::cout << "P95 latency: " << p95Latency << " microseconds" << std::endl;
    return 0;
}
