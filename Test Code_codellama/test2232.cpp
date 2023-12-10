#include <unordered_map>
#include <string>

using namespace std;

// Hash table to store the registered system IDs
unordered_map<string, bool> systemIDs;

// Function to register a new system ID for parallel processing
void registerSystemID(string systemID) {
    systemIDs[systemID] = true;
}

// Function to remove an existing system ID from the parallel processing system
void removeSystemID(string systemID) {
    systemIDs.erase(systemID);
}

// Function to check if a given system ID is already registered for parallel processing
bool isSystemIDRegistered(string systemID) {
    return systemIDs.find(systemID) != systemIDs.end();
}

// Function to retrieve the total count of registered system IDs for parallel processing
int getTotalSystemIDCount() {
    return systemIDs.size();
}
