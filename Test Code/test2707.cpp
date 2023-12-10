#include <benchmark/benchmark.h>
#include <glog/logging.h>

// Define the status logging plugin
class StatusLogger {
public:
    void logStatus(const std::string& message) {
        LOG(INFO) << "Status: " << message;
    }
};

// Define the string logging plugin
class StringLogger {
public:
    void logString(const std::string& message) {
        LOG(INFO) << "String: " << message;
    }
};

// Benchmark the status logging plugin
static void LOGGER_logstatus_plugin(benchmark::State& state) {
    StatusLogger logger;
    for (auto _ : state) {
        logger.logStatus("Logging status message");
    }
}
BENCHMARK(LOGGER_logstatus_plugin);

// Benchmark the string logging plugin
static void LOGGER_logstring_plugin(benchmark::State& state) {
    StringLogger logger;
    for (auto _ : state) {
        logger.logString("Logging string message");
    }
}
BENCHMARK(LOGGER_logstring_plugin);

int main(int argc, char** argv) {
    google::InitGoogleLogging(argv[0]);
    google::ParseCommandLineFlags(&argc, &argv);
    ::benchmark::Initialize(&argc, argv);
    ::benchmark::RunSpecifiedBenchmarks();
}
