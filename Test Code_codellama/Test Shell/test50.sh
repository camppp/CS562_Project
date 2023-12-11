#include <string.h>
#include <stdlib.h>

char* cfg_server_address(const char* section) {
    char* server_address = NULL;
    char* line = NULL;
    FILE* file = fopen("config.ini", "r");
    if (file == NULL) {
        return NULL;
    }
    while ((line = fgets(file)) != NULL) {
        if (strncmp(line, section, strlen(section)) == 0) {
            char* key = strtok(line, "=");
            char* value = strtok(NULL, "=");
            if (strcmp(key, "server_address") == 0) {
                server_address = strdup(value);
                break;
            }
        }
    }
    fclose(file);
    return server_address;
}