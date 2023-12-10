#include <iostream>

class MemoryMonitor {
private:
    size_t _num_of_classes;
    size_t _num_of_threads;

public:
    void startMonitoring(size_t scale, bool report_diff = false) {
        start(scale, report_diff);
    }

    void finishMonitoring() {
        done();
    }

    void trackMemoryUsage(size_t total_reserved, size_t total_committed) {
        total_usage(total_reserved, total_committed);
    }

    void trackLoadedClasses(size_t classes) {
        _num_of_classes = classes;
        num_of_classes(classes);
    }

    void trackNumberOfThreads(size_t threads) {
        _num_of_threads = threads;
        num_of_threads(threads);
    }

    // Mock implementation of the provided functions for demonstration purposes
    void start(size_t scale, bool report_diff) {
        std::cout << "Monitoring started with scale: " << scale << ", report_diff: " << report_diff << std::endl;
    }

    void done() {
        std::cout << "Monitoring done" << std::endl;
    }

    void total_usage(size_t total_reserved, size_t total_committed) {
        std::cout << "Total memory usage - Reserved: " << total_reserved << ", Committed: " << total_committed << std::endl;
    }

    void num_of_classes(size_t classes) {
        std::cout << "Number of loaded classes: " << classes << std::endl;
    }

    void num_of_threads(size_t threads) {
        std::cout << "Number of threads: " << threads << std::endl;
    }
};

int main() {
    MemoryMonitor monitor;
    monitor.startMonitoring(100, true);
    monitor.trackMemoryUsage(1024, 512);
    monitor.trackLoadedClasses(50);
    monitor.trackNumberOfThreads(8);
    monitor.finishMonitoring();

    return 0;
}
