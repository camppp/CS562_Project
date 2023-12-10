#include <cstdint>

const int MAX_CHUNKS = 100; // Maximum number of memory chunks

struct Chunk {
    int lock; // Lock status of the chunk (0 for unlocked, 1 for locked)
    int usage; // Usage of the chunk
    // Other chunk properties
};

typedef uint64_t ID; // ID type for memory chunks

class MemoryPoolDynamicStatic {
private:
    Chunk chunk[MAX_CHUNKS]; // Array of memory chunks
    int total_usage; // Total memory usage
    int max_usage; // Maximum memory usage

public:
    ID allocate(int p_amount) {
        for (int idx = 0; idx < MAX_CHUNKS; ++idx) {
            if (chunk[idx].lock == 0) {
                chunk[idx].lock = 1; // Set the lock to 1 to allocate the chunk
                total_usage += p_amount; // Update the total usage
                if (total_usage > max_usage) {
                    max_usage = total_usage; // Update the maximum usage if necessary
                }
                ID id = chunk[idx].usage * MAX_CHUNKS + static_cast<uint64_t>(idx); // Calculate the ID
                return id; // Return the allocated ID
            }
        }
        // Handle the case when no available chunk is found (e.g., return a special ID or throw an exception)
    }

    void free(ID p_id) {
        int chunk_idx = p_id % MAX_CHUNKS; // Extract the chunk index from the ID
        int usage_idx = p_id / MAX_CHUNKS; // Extract the usage index from the ID
        if (chunk_idx >= 0 && chunk_idx < MAX_CHUNKS) {
            chunk[chunk_idx].lock = 0; // Set the lock to 0 to deallocate the chunk
            total_usage -= chunk[chunk_idx].usage; // Update the total usage
            // Other deallocation operations if necessary
        }
        // Handle the case when the provided ID is invalid (e.g., throw an exception)
    }
};
