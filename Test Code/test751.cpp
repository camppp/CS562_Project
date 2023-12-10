#include <string>

class KafkaConfiguration {
    // Define KafkaConfiguration properties and methods
};

class KafkaProducerConfig {
private:
    KafkaConfiguration producer;
    std::string configuration_file{""};
    std::string source{""};
    std::string source_name{"AMOR.event.stream"};
    std::string timestamp_generator{"none"};
    int multiplier{0};
    int bytes{0};
    int rate{0};
    int report_time{10};
    int num_threads{0};

public:
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
};
