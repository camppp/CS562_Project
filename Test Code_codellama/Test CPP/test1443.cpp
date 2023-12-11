c
void set_caches(cache_t *caches, int num_caches) {
    for (int i = 0; i < num_caches; i++) {
        cache_t *cache = &caches[i];
        // Set the cache ID
        cache->id = i + 1;
        // Set the cache size
        cache->size = 1024;
        // Set the cache type
        strcpy(cache->type, "L1");
    }
}
