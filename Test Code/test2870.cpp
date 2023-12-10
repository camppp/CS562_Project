#include <iostream>

int main() {
    PlacementManager manager;

    // Add placement information
    manager.addPlacement("AWS", "us-east-1", "a", 3);
    manager.addPlacement("GCP", "us-central1", "b", 2);
    manager.addPlacement("Azure", "eastus", "1", 4);

    // Retrieve total minimum replicas
    std::cout << "Total minimum replicas: " << manager.getTotalMinReplicas() << std::endl;

    return 0;
}
