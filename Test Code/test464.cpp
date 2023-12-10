#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <librdkafka/rdkafka.h>

// Structure to store parsed configuration properties
typedef struct {
    char* key;
    char* value;
} ParsedInfo;

// Function to parse Kafka configuration properties
ParsedInfo* parseKafkaConfig(rd_kafka_conf_t* conf) {
    ParsedInfo* parsedInfo = NULL;
    char builtin_features[120] = {0};
    size_t len_size = sizeof(builtin_features);
    rd_kafka_conf_get(conf, "builtin.features", builtin_features, &len_size);

    // Parse the configuration property and store it in the ParsedInfo structure
    parsedInfo = (ParsedInfo*)malloc(sizeof(ParsedInfo));
    parsedInfo->key = strdup("builtin.features");
    parsedInfo->value = strdup(builtin_features);

    return parsedInfo;
}

int main() {
    rd_kafka_conf_t *conf = rd_kafka_conf_new();

    char builtin_features[120] = {0};
    size_t len_size = sizeof(builtin_features);
    rd_kafka_conf_get(conf, "builtin.features", builtin_features, &len_size);
    printf("builtin.features: <%s>.\n", builtin_features);

    // Call the function to parse Kafka configuration properties
    ParsedInfo* info = parseKafkaConfig(conf);
    // Process the parsed information
    printf("Parsed Info: key=<%s>, value=<%s>\n", info->key, info->value);
    // Free the memory allocated for parsed information
    free(info->key);
    free(info->value);
    free(info);

    return 0;
}
