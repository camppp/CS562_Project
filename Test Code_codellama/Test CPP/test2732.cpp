class MemoryMonitor {
public:
    MemoryMonitor(size_t scale, bool report_diff = false) {
        startMonitoring(scale, report_diff);
    }

    ~MemoryMonitor() {
        finishMonitoring();
    }

    void startMonitoring(size_t scale, bool report_diff = false) {
        _scale = scale;
        _report_diff = report_diff;
        start(scale, report_diff);
    }

    void finishMonitoring() {
        done();
    }

    void trackMemoryUsage(size_t total_reserved, size_t total_committed) {
        total_usage(total_reserved, total_committed);
    }

    void trackLoadedClasses(size_t classes) {
        num_of_classes(classes);
    }

    void trackNumberOfThreads(size_t threads) {
        num_of_threads(threads);
    }

private:
    size_t _scale;
    bool _report_diff;
};
