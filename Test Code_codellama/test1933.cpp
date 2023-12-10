#include <unordered_map>
#include <mutex>

class ChunkManager {
public:
    // Constructor
    ChunkManager() {
        // Initialize the chunk map
        chunks_ = std::unordered_map<ChunkIt_t, ChunkInfo_t>();
    }

    // Allocate a new chunk of data with the specified size
    ChunkIt_t AllocateChunk(size_t size) {
        // Acquire the mutex to prevent concurrent access
        std::lock_guard<std::mutex> lock(mutex_);

        // Create a new chunk with the specified size
        ChunkIt_t chunk = ChunkIt_t(size);

        // Add the chunk to the chunk map
        chunks_.insert(std::make_pair(chunk, ChunkInfo_t(chunk, size)));

        // Return the unique identifier for the chunk
        return chunk;
    }

    // Deallocate an existing chunk of data
    void DeallocateChunk(ChunkIt_t chunk) {
        // Acquire the mutex to prevent concurrent access
        std::lock_guard<std::mutex> lock(mutex_);

        // Remove the chunk from the chunk map
        chunks_.erase(chunk);
    }

    // Mark a chunk as valid or invalid
    void MarkChunkValid(ChunkIt_t chunk, bool valid) {
        // Acquire the mutex to prevent concurrent access
        std::lock_guard<std::mutex> lock(mutex_);

        // Get the chunk information
        ChunkInfo_t& chunk_info = chunks_[chunk];

        // Set the validity flag
        chunk_info.valid = valid;
    }

    // Check if the last modification made to a chunk is valid
    bool IsLastModifyValid(ChunkIt_t chunk) {
        // Acquire the mutex to prevent concurrent access
        std::lock_guard<std::mutex> lock(mutex_);

        // Get the chunk information
        ChunkInfo_t& chunk_info = chunks_[chunk];

        // Return the validity flag
        return chunk_info.valid;
    }

    // Check if a chunk is currently in use (i.e., being modified)
    bool IsChunkInUse(ChunkIt_t chunk) {
        // Acquire the mutex to prevent concurrent access
        std::lock_guard<std::mutex> lock(mutex_);

        // Get the chunk information
        ChunkInfo_t& chunk_info = chunks_[chunk];

        // Return true if the chunk is being modified, otherwise return false
        return chunk_info.in_use;
    }

private:
    // The chunk map
    std::unordered_map<ChunkIt_t, ChunkInfo_t> chunks_;

    // The mutex to prevent concurrent access to the chunk map
    std::mutex mutex_;
};
