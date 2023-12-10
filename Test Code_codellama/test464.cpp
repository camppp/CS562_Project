c
#include <stdio.h>
#include <string.h>
#include <librdkafka/rdkafka.h>

// Data structure to represent the parsed Kafka configuration properties
typedef struct {
    char* builtin_features;
} ParsedInfo;

// Function to parse Kafka configuration properties
ParsedInfo* parseKafkaConfig(rd_kafka_conf_t* conf) {
    // Allocate memory for the parsed information
    ParsedInfo* info = (ParsedInfo*) malloc(sizeof(ParsedInfo));
    if (info == NULL) {
        fprintf(stderr, "Failed to allocate memory for parsed information\n");
        return NULL;
    }

    // Retrieve the "builtin.features" configuration property from the Kafka configuration object
    char builtin_features[120] = {0};
    size_t len_size = sizeof(builtin_features);
    rd_kafka_conf_get(conf, "builtin.features", builtin_features, &len_size);

    // Parse the configuration property and store it in the data structure
    info->builtin_features = builtin_features;

    return info;
}

int main() {
    rd_kafka_conf_t *conf = rd_kafka_conf_new();

    // Call the function to parse Kafka configuration properties
    ParsedInfo* info = parseKafkaConfig(conf);
    if (info == NULL) {
        fprintf(stderr, "Failed to parse Kafka configuration properties\n");
        return 1;
    }

    // Process the parsed information
    printf("Parsed Kafka configuration properties:\n");
    printf("  builtin.features: %s\n", info->builtin_features);

    // Free the memory allocated for parsed information
    freeParsedInfo(info);

    return 0;
}
