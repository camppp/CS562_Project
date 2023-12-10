#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// Data structures
struct ConnMap_t {
    std::unordered_map<std::string, serv_info_t*> connMap;
};

struct serv_info_t {
    std::string serverName;
    std::string serverAddress;
    int serverPort;
};

// Global variables
static ConnMap_t g_login_server_conn_map;
static std::vector<serv_info_t*> g_login_server_list;
static int g_login_server_count = 0;

// Function definitions
void initializeConnectionMap(ConnMap_t* connMap) {
    connMap->connMap.clear();
}

void addServerInfo(serv_info_t* serverInfo) {
    g_login_server_list.push_back(serverInfo);
    g_login_server_count++;
}

void removeServerInfo(serv_info_t* serverInfo) {
    for (int i = 0; i < g_login_server_count; i++) {
        if (g_login_server_list[i] == serverInfo) {
            g_login_server_list.erase(g_login_server_list.begin() + i);
            g_login_server_count--;
            break;
        }
    }
}

serv_info_t* findServerInfo(const char* serverName) {
    for (int i = 0; i < g_login_server_count; i++) {
        if (strcmp(g_login_server_list[i]->serverName, serverName) == 0) {
            return g_login_server_list[i];
        }
    }
    return nullptr;
}
