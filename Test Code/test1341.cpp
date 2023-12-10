#include <iostream>
#include <vector>
#include "FWCore/Framework/interface/eventsetuprecord_registration_macro.h"

class EventSetupManager {
public:
    void registerRecord(const std::string& recordName) {
        // Use the provided macro to register the record
        EVENTSETUP_RECORD_REG(EventSetupManager, recordName);
    }

    std::vector<std::string> getRegisteredRecords() {
        // Simulate retrieving the registered records
        std::vector<std::string> registeredRecords = {"Record1", "Record2", "Record3"};
        return registeredRecords;
    }
};

int main() {
    EventSetupManager manager;

    // Register some records
    manager.registerRecord("Record1");
    manager.registerRecord("Record2");
    manager.registerRecord("Record3");

    // Retrieve and print the registered records
    std::vector<std::string> records = manager.getRegisteredRecords();
    std::cout << "Registered Records:" << std::endl;
    for (const auto& record : records) {
        std::cout << record << std::endl;
    }

    return 0;
}
