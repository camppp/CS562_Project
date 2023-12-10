#include <string>

class KafkaProducerConfig {
public:
    KafkaProducerConfig() {}

    void setConfigurationFile(const std::string& file) {
        configuration_file = file;
    }

    void setSource(const std::string& src) {
        source = src;
    }

    void setSourceName(const std::string& name) {
        source_name = name;
    }

    void setTimestampGenerator(const std::string& generator) {
        timestamp_generator = generator;
    }

    void setMultiplier(int value) {
        multiplier = value;
    }

    void setBytes(int size) {
        bytes = size;
    }

    void setRate(int streamingRate) {
        rate = streamingRate;
    }

    void setReportTime(int interval) {
        report_time = interval;
    }

    void setNumThreads(int threads) {
        num_threads = threads;
    }

private:
    std::string configuration_file;
    std::string source;
    std::string source_name;
    std::string timestamp_generator;
    int multiplier;
    int bytes;
    int rate;
    int report_time;
    int num_threads;
};
