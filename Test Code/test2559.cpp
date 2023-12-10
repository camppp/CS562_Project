#include <iostream>
#include <vector>

class FilterDescriptor {
public:
    FilterDescriptor(int filterType) : filterType_(filterType) {}

    int getFilterType() { return filterType_; }

private:
    int filterType_;
};

class DeviceDescriptor {
public:
    DeviceDescriptor() : dispatchTable_(nullptr) {}

    void addFilterDescriptor(FilterDescriptor* filterDescriptor) {
        filterDescriptors_.push_back(filterDescriptor);
    }

    void* getDispatchTable() { return dispatchTable_; }

    void createFilterFactories() {
        for (auto& filterDescriptor : filterDescriptors_) {
            KsCreateFilterFactory(filterDescriptor->getFilterType(), &filterDescriptor->getDispatchTable());
        }
    }

private:
    std::vector<FilterDescriptor*> filterDescriptors_;
    void* dispatchTable_;
};

int main() {
    DeviceDescriptor deviceDescriptor;

    // Add filter descriptors to the device descriptor
    FilterDescriptor* filterDescriptor1 = new FilterDescriptor(1);
    deviceDescriptor.addFilterDescriptor(filterDescriptor1);
    FilterDescriptor* filterDescriptor2 = new FilterDescriptor(2);
    deviceDescriptor.addFilterDescriptor(filterDescriptor2);

    // Create filter factories using the dispatch table
    deviceDescriptor.createFilterFactories();

    // Retrieve the dispatch table pointer
    void* dispatchTable = deviceDescriptor.getDispatchTable();

    // Use the dispatch table to create filters
    // ...

    // Clean up
    delete filterDescriptor1;
    delete filterDescriptor2;

    return 0;
}
