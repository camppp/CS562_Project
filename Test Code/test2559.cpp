#include <iostream>
#include <vector>

// Assume the existence of KsCreateFilterFactory function for creating filter factories

class FilterDescriptor {
private:
    std::string filterType;

public:
    FilterDescriptor(const std::string& type) : filterType(type) {}

    std::string getFilterType() const {
        return filterType;
    }
};

class DeviceDescriptor {
private:
    void* dispatchTable;
    std::vector<FilterDescriptor> filterDescriptors;

public:
    DeviceDescriptor() : dispatchTable(nullptr) {}

    void addFilterDescriptor(const std::string& type) {
        filterDescriptors.emplace_back(type);
    }

    void* getDispatchTable() const {
        return dispatchTable;
    }

    void createFilterFactory() {
        // Assume the existence of KsCreateFilterFactory function for creating filter factories
        // Example usage: KsCreateFilterFactory(filterType);
        std::cout << "Filter factory created for each filter descriptor." << std::endl;
    }
};

int main() {
    DeviceDescriptor device;

    // Adding filter descriptors
    device.addFilterDescriptor("FilterType1");
    device.addFilterDescriptor("FilterType2");
    device.addFilterDescriptor("FilterType3");

    // Retrieving dispatch table pointer
    void* dispatchTable = device.getDispatchTable();

    // Creating filter factories
    device.createFilterFactory();

    return 0;
}
