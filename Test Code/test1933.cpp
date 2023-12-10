#include <mutex>
#include <unordered_map>

struct ChunkIt_t {
    size_t size;
    bool valid;
    bool lastModifyValid;
    bool inUse;
};

class ChunkManager {
public:
    ChunkIt_t AllocateChunk(size_t size) {
        std::lock_guard<std::mutex> lock(mutex_);
        ChunkIt_t chunk;
        chunk.size = size;
        chunk.valid = false;
        chunk.lastModifyValid = false;
        chunk.inUse = true;
        chunks_[nextId_] = chunk;
        return nextId_++;
    }

    void DeallocateChunk(ChunkIt_t chunkId) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = chunks_.find(chunkId);
        if (it != chunks_.end()) {
            it->second.inUse = false;
            chunks_.erase(it);
        }
    }

    void MarkChunkValid(ChunkIt_t chunkId) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = chunks_.find(chunkId);
        if (it != chunks_.end()) {
            it->second.valid = true;
        }
    }

    void MarkChunkInvalid(ChunkIt_t chunkId) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = chunks_.find(chunkId);
        if (it != chunks_.end()) {
            it->second.valid = false;
        }
    }

    bool IsLastModifyValid(ChunkIt_t chunkId) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = chunks_.find(chunkId);
        if (it != chunks_.end()) {
            return it->second.lastModifyValid;
        }
        return false;
    }

    bool IsChunkInUse(ChunkIt_t chunkId) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = chunks_.find(chunkId);
        if (it != chunks_.end()) {
            return it->second.inUse;
        }
        return false;
    }

private:
    std::mutex mutex_;
    std::unordered_map<ChunkIt_t, ChunkIt_t> chunks_;
    ChunkIt_t nextId_ = 0;
};
