#include <iostream>
#include <vector>

class MemoryStatistics {
public:
    MemoryStatistics() : total_allocated_(0), total_freed_(0), peak_usage_(0) {}

    void update(size_t allocated, size_t freed) {
        total_allocated_ += allocated;
        total_freed_ += freed;
        peak_usage_ = std::max(peak_usage_, total_allocated_ - total_freed_);
    }

    size_t getTotalAllocated() const { return total_allocated_; }
    size_t getTotalFreed() const { return total_freed_; }
    size_t getPeakUsage() const { return peak_usage_; }

private:
    size_t total_allocated_;
    size_t total_freed_;
    size_t peak_usage_;
};

class StatisticsMemory {
public:
    StatisticsMemory(void* target) : target_(target), statistics_() {}

    void updateStatistics(size_t allocated, size_t freed) {
        statistics_.update(allocated, freed);
    }

    size_t getMemoryUsage() const {
        return statistics_.getTotalAllocated() - statistics_.getTotalFreed();
    }

    void flush() {
        if (target_) {
            target_->flush();
        }
    }

    MemoryStatistics& statistics() { return statistics_; }

private:
    void* target_;
    MemoryStatistics statistics_;
};
