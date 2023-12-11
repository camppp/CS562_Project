c
#include <stdio.h>
#include <hwloc.h>

void assignThreadsToCores(int numThreads, int numCores) {
    // Get the topology of the machine
    hwloc_topology_t topology;
    hwloc_topology_init(&topology);
    hwloc_topology_load(topology);

    // Get the number of cores in the machine
    int numCores = hwloc_get_nbobjs_by_type(topology, HWLOC_OBJ_CORE);

    // Allocate the threads to the cores
    if (numThreads <= numCores) {
        // Each thread gets its own core
        for (int i = 0; i < numThreads; i++) {
            hwloc_set_cpubind(topology, i, HWLOC_CPUBIND_THREAD);
        }
    } else {
        // Distribute the threads evenly across the cores
        int threadsPerCore = numThreads / numCores;
        int threadsRemaining = numThreads % numCores;
        for (int i = 0; i < numCores; i++) {
            int numThreadsToBind = threadsPerCore;
            if (i < threadsRemaining) {
                numThreadsToBind++;
            }
            for (int j = 0; j < numThreadsToBind; j++) {
                hwloc_set_cpubind(topology, i * threadsPerCore + j, HWLOC_CPUBIND_THREAD);
            }
        }
    }

    // Free the topology
    hwloc_topology_destroy(topology);
}
