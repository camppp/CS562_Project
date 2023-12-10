#include <stdio.h>
#include <hwloc.h>

void assignThreadsToCores(int numThreads, int numCores) {
    hwloc_topology_t topology;
    hwloc_obj_t obj;
    hwloc_cpuset_t cpuset;
    int i;

    // Allocate and initialize topology object
    hwloc_topology_init(&topology);
    hwloc_topology_load(topology);

    // Set the object type and name for assigning threads to real cores
    hwloc_obj_type_t obj_type = HWLOC_OBJ_CORE;
    const char *obj_name = "Core";

    // Iterate through the available cores and assign threads
    for (i = 0; i < numThreads; i++) {
        obj = hwloc_get_obj_by_type(topology, obj_type, i % numCores);
        cpuset = hwloc_bitmap_dup(obj->cpuset);
        hwloc_bitmap_singlify(cpuset);
        hwloc_set_cpubind(topology, cpuset, HWLOC_CPUBIND_THREAD);
        hwloc_bitmap_free(cpuset);
    }

    // Destroy topology object
    hwloc_topology_destroy(topology);
}
