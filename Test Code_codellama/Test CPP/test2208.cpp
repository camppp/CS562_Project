class MemoryPoolDynamicStatic {
public:
    // Allocate a memory chunk and return its ID
    int allocate() {
        // Find an available chunk
        for (int i = 0; i < numChunks; i++) {
            if (chunks[i].lock == 0) {
                chunks[i].lock = 1;
                totalUsage += chunks[i].size;
                return chunks[i].id;
            }
        }
        // No available chunk found, return -1
        return -1;
    }

    // Deallocate a memory chunk based on its ID
    void free(int id) {
        // Find the chunk with the provided ID
        for (int i = 0; i < numChunks; i++) {
            if (chunks[i].id == id) {
                chunks[i].lock = 0;
                totalUsage -= chunks[i].size;
                return;
            }
        }
        // Chunk not found, do nothing
    }

private:
    struct Chunk {
        int id;
        int size;
        int lock;
    };

    int numChunks;
    Chunk chunks[MAX_CHUNKS];
    int totalUsage;
};
