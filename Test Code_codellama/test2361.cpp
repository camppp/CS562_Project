#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

struct USDevice {
    std::string name;
    std::string manufacturer;
    int serialNumber;
    struct Probe {
        std::string type;
        std::string frequency;
    } probe;
};

std::vector<USDevice> parseUSDevices(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: unable to open file " << filename << std::endl;
        return {};
    }

    std::string line;
    std::vector<USDevice> devices;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string tag;
        ss >> tag;
        if (tag == "<Device>") {
            USDevice device;
            while (ss >> tag) {
                if (tag == "<Name>") {
                    ss >> device.name;
                } else if (tag == "<Manufacturer>") {
                    ss >> device.manufacturer;
                } else if (tag == "<SerialNumber>") {
                    ss >> device.serialNumber;
                } else if (tag == "<Probe>") {
                    device.probe.type = ss.substr(ss.find("<Type>") + 5, ss.find("</Type>") - ss.find("<Type>") - 5);
                    device.probe.frequency = ss.substr(ss.find("<Frequency>") + 9, ss.find("</Frequency>") - ss.find("<Frequency>") - 9);
                }
            }
            devices.push_back(device);
        }
    }

    return devices;
}

int main() {
    std::vector<USDevice> devices = parseUSDevices("us_devices.xml");
    for (const auto& device : devices) {
        std::cout << "Device: " << device.name << std::endl;
        std::cout << "Manufacturer: " << device.manufacturer << std::endl;
        std::cout << "Serial Number: " << device.serialNumber << std::endl;
        std::cout << "Probe Type: " << device.probe.type << std::endl;
        std::cout << "Probe Frequency: " << device.probe.frequency << std::endl;
    }

    return 0;
}
