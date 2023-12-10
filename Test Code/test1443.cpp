#include <stdio.h>

typedef struct {
    int id;
    int size;
    char type[20];
} cache_t;

void set_caches(cache_t *caches, int num_caches) {
    for (int i = 0; i < num_caches; i++) {
        printf("Setting attributes for cache %d:\n", caches[i].id);
        printf("Size: %d\n", caches[i].size);
        printf("Type: %s\n", caches[i].type);
        // Additional logic to set the attributes of the cache objects
        // This could involve interacting with hardware or updating internal data structures
        // For the purpose of this problem, the actual attribute setting logic is omitted
        printf("Attributes set for cache %d\n", caches[i].id);
        printf("\n");
    }
}

int main() {
    cache_t cache_list[] = {
        {1, 1024, "L1 Cache"},
        {2, 2048, "L2 Cache"},
        {3, 4096, "L3 Cache"}
    };
    int num_caches = sizeof(cache_list) / sizeof(cache_list[0]);

    set_caches(cache_list, num_caches);

    return 0;
}
