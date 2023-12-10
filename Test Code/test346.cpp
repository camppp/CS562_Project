#include <iostream>

// Define the structure pointed to by PTR
struct Host {
    const wchar_t* pNameHost;
};

// Define the structure containing the pointer to Host
struct Data {
    Host* PTR;
};

// Define the main structure
struct MainStructure {
    Data Data;
};

// Function to extract and print specific information from the data structure
void printHostInfo(const MainStructure* r) {
    if (r != nullptr && r->Data.PTR != nullptr && r->Data.PTR->pNameHost != nullptr) {
        std::wcout << "- PTR: " << r->Data.PTR->pNameHost << std::endl;
    } else {
        std::wcout << "Invalid data or pointer" << std::endl;
    }
}

int main() {
    // Example usage
    Host host1 = { L"ExampleHost" };
    Data data1 = { &host1 };
    MainStructure mainStruct = { data1 };

    printHostInfo(&mainStruct);  // Output: - PTR: ExampleHost

    return 0;
}
