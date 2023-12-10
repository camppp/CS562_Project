#include <stdio.h>
#include <string.h>

// Define the types for connection map and server information
typedef struct {
    // Define the structure for connection map
    // (implementation details depend on the specific requirements)
} ConnMap_t;

typedef struct {
    char serverName[50];
    // Add any other relevant server information fields
} serv_info_t;

static ConnMap_t g_login_server_conn_map;
static serv_info_t g_login_server_list[100]; // Assuming a maximum of 100 login servers
static uint32_t g_login_server_count = 0;

// Initialize the connection map
void initializeConnectionMap(ConnMap_t* connMap) {
    // Implementation details for initializing the connection map
}

// Add server information to the server list
void addServerInfo(serv_info_t* serverInfo) {
    if (g_login_server_count < 100) { // Check if the server list is not full
        g_login_server_list[g_login_server_count++] = *serverInfo;
    } else {
        printf("Server list is full. Cannot add more servers.\n");
    }
}

// Remove server information from the server list
void removeServerInfo(serv_info_t* serverInfo) {
    for (int i = 0; i < g_login_server_count; i++) {
        if (strcmp(g_login_server_list[i].serverName, serverInfo->serverName) == 0) {
            // Shift elements to overwrite the removed server info
            for (int j = i; j < g_login_server_count - 1; j++) {
                g_login_server_list[j] = g_login_server_list[j + 1];
            }
            g_login_server_count--;
            printf("Server '%s' removed from the list.\n", serverInfo->serverName);
            return;
        }
    }
    printf("Server '%s' not found in the list.\n", serverInfo->serverName);
}

// Find server information by server name in the server list
serv_info_t* findServerInfo(const char* serverName) {
    for (int i = 0; i < g_login_server_count; i++) {
        if (strcmp(g_login_server_list[i].serverName, serverName) == 0) {
            return &g_login_server_list[i];
        }
    }
    return NULL; // Server not found
}
