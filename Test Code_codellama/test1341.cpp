#include <iostream>
#include <vector>
#include "eventsetuprecord_registration_macro.h"

class EventSetupManager {
public:
    void registerRecord(const std::string& recordName) {
        // Use the provided macro to register the record
        EVENTSETUP_REGISTER_RECORD(recordName);
    }

    std::vector<std::string> getRegisteredRecords() {
        // Return a list of all the registered records
        return EVENTSETUP_GET_REGISTERED_RECORDS();
    }
};

int main() {
    // Create an instance of the EventSetupManager class
    EventSetupManager manager;

    // Register some records
    manager.registerRecord("MyRecord1");
    manager.registerRecord("MyRecord2");
    manager.registerRecord("MyRecord3");

    // Retrieve and print the registered records
    std::vector<std::string> registeredRecords = manager.getRegisteredRecords();
    for (const std::string& record : registeredRecords) {
        std::cout << "Registered record: " << record << std::endl;
    }

    return 0;
}
